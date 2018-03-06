#include "lz77_encoding_function.h"


// Return the max of two integers
int min(int a, int b){
	return a > b ? b : a;
}


// Using a single integer position, determine the character referenced in the pgm image
unsigned char get_pgm_image_value(struct PGM_Image* image, int pos){
	return image->image[(int)floor(pos / image->width)][pos % image->width];
}


// Determine the number of matching characters when using an offset of match_pos
// and a frontier of text_pos
int find_number_of_matches(struct PGM_Image* image, int match_pos, int text_pos, int total){
	int match_num = 0;
	while(get_pgm_image_value(image, match_pos) == get_pgm_image_value(image, text_pos)){
		match_num++;
		match_pos++;
		text_pos++;

		if(match_pos >= total || text_pos >= total){
			break;
		}
	}
	return match_num;
}


void Encode_Using_LZ77(char *in_PGM_filename_Ptr, unsigned int searching_buffer_size, 
	float *avg_offset_Ptr, float *std_offset_Ptr, float *avg_length_Ptr, 
	float *std_length_Ptr){
	
	// loading the image
	struct PGM_Image* image = malloc(sizeof(struct PGM_Image));
	load_PGM_Image(image, in_PGM_filename_Ptr);
	int total = image->width * image->height;

	// Storing the token data
	int* offsets = calloc(total, sizeof(int));
	int* match_lengths = calloc(total, sizeof(int));
	char* mismatches = malloc(total * sizeof(int));
	int number_of_tokens = 0;

	int max_match_pos;			// offset
	int max_match_num;			// match length
	int cur_pos = 0;			// current position within the image
	unsigned char cur_value;


	/*** DETERMINING TOKENS ***/

	while(cur_pos < total - 1){

		max_match_num = 0;
		max_match_pos = 0;

		// Get the next value in the image
		cur_value = get_pgm_image_value(image, cur_pos);

		// Searching backwards through the buffer
		for(int i = 1; i <= min(cur_pos, searching_buffer_size); i++){

			// If we find a match
			if(get_pgm_image_value(image, cur_pos - i) == cur_value){

				// If we find the match matches a larger number than previously seen update max values
				int temp = find_number_of_matches(image, cur_pos - i, cur_pos, total);
				if(temp > max_match_num){
					max_match_num = temp;
					max_match_pos = i;
				}
			}
		}

		// Update the token information
		offsets[number_of_tokens] = max_match_pos;				// offset away
		match_lengths[number_of_tokens] = max_match_num;		// how long the match was
		mismatches[number_of_tokens++] = get_pgm_image_value(image, cur_pos + max_match_num);	// the value after the match

		// Update the current position to be the position after the next mismatch
		cur_pos += max_match_num + 1;
	}


	/*** SAVING COMPRESSED IMAGE + HEADER ***/

	// Building the header
	struct header* file_header = malloc(sizeof(struct header));
	file_header->max_offset = searching_buffer_size;
	file_header->number_of_tokens = number_of_tokens;
	file_header->width = image->width;
	file_header->height = image->height;
	file_header->max_gray_value = MAX_GRAY_VALUE;

	// Creating altered filename for output (lz)
	char numstr1[100];
	sprintf(numstr1, "%s.%d.lz", in_PGM_filename_Ptr, searching_buffer_size);
	FILE *f = fopen(numstr1, "wb");

	// Writing to file
	fwrite(file_header, sizeof(struct header), 1, f);
	fwrite(offsets, sizeof(int), number_of_tokens, f);
	fwrite(match_lengths, sizeof(int), number_of_tokens, f);
	fwrite(mismatches, sizeof(int), number_of_tokens, f);

	fclose(f);

	free(mismatches);
	free(file_header);
	free(image);

	/*** OFFSETS ***/

	// Determining the frequencies of all of the offsets
	int* offset_frequencies = calloc(searching_buffer_size, sizeof(int));
	for(int i = 0; i < number_of_tokens; i++){
		offset_frequencies[offsets[i]]++;
	}

	// Creating altered filename for output (csv)
	char numstr2[100];
	sprintf(numstr2, "%s.%d.offsets.csv", in_PGM_filename_Ptr, searching_buffer_size);

	// Writing the offsets
	f = fopen(numstr2, "w");
	for(int i = 1; i <= searching_buffer_size; i++){
		fprintf(f, "%d, %d\n", i, offset_frequencies[i]);
	}
	fclose(f);
	free(offset_frequencies);


	/*** MATCH LENGTHS ***/

	// Determining the range of match lengths
	int max_match_length = 0;
	for(int i = 0; i < number_of_tokens; i++){
		if(match_lengths[i] > max_match_length){
			max_match_length = match_lengths[i];
		}
	}

	// Determining the frequencies of match lengths
	int* match_length_frequencies = calloc(max_match_length + 1, sizeof(int));
	for(int i = 0; i < number_of_tokens; i++){
		match_length_frequencies[match_lengths[i]]++;
	}

	// // Creating altered filename for output (csv)
	char numstr3[100];
	sprintf(numstr3, "%s.%d.lengths.csv", in_PGM_filename_Ptr, searching_buffer_size);

	// Writing the match lengths
	f = fopen(numstr3, "w");
	for(int i = 1; i <= max_match_length; i++){
		fprintf(f, "%d, %d\n", i, match_length_frequencies[i]);
	}
	fclose(f);
	free(match_length_frequencies);


	/*** AVERAGE + STANDARD DEVIATION ***/

	// Calculating the average
	*avg_offset_Ptr = 0.0;
	*avg_length_Ptr = 0.0;
	for(int i = 0; i < number_of_tokens; i++){
		*avg_offset_Ptr += offsets[i];
		*avg_length_Ptr += match_lengths[i];
	}
	*avg_offset_Ptr /= number_of_tokens;
	*avg_length_Ptr /= number_of_tokens;


	// Calculating standard deviation
	*std_offset_Ptr = 0.0;
	*std_length_Ptr = 0.0;
	for(int i = 0; i < number_of_tokens; i++){
		*std_offset_Ptr += pow(offsets[i] - *avg_offset_Ptr, 2);
		*std_length_Ptr += pow(match_lengths[i] - *avg_length_Ptr, 2);
	}
	*std_offset_Ptr = sqrt(*avg_offset_Ptr / number_of_tokens);
	*std_length_Ptr = sqrt(*avg_length_Ptr / number_of_tokens);

	// Clearing all freed memory
	free(offsets);
	free(match_lengths);
}
