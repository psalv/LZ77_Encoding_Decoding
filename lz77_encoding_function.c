#include "lz77_encoding_function.h"


// Return the max of two integers
int max(int a, int b){
	return a > b ? a : b;
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
	int* offsets = malloc(total * sizeof(int));
	int* match_lengths = malloc(total * sizeof(int));
	char* mismatches = malloc(total * sizeof(int));
	int number_of_tokens = 0;

	int max_match_pos;			// offset
	int max_match_num;			// match length
	int cur_pos = 0;			// current position within the image
	unsigned char cur_value;
	while(cur_pos < total){
		max_match_num = 0;
		max_match_num = 0;

		// Get the next value in the image
		cur_value = get_pgm_image_value(image, cur_pos);

		// Searching backwards through the buffer
		for(int i = 0; i > max(0, cur_pos - searching_buffer_size); i--){

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

	// Building the header
	struct header* file_header = malloc(sizeof(struct header));
	file_header->max_offset = searching_buffer_size;
	file_header->number_of_tokens = number_of_tokens;
	file_header->width = image->width;
	file_header->height = image->height;
	file_header->max_gray_value = MAX_GRAY_VALUE;

	// Creating altered filename for output (lz)
	char numstr1[21];
	char* new_file_name1 = in_PGM_filename_Ptr + '1';
	// char* new_file_name1 = in_PGM_filename_Ptr + itoa(searching_buffer_size, numstr1, 10);
	strcat(new_file_name1, "lz");

	FILE *f = fopen(new_file_name1, "wb");

	// Writing to file
	fwrite(file_header, sizeof(struct header), 1, f);
	fwrite(offsets, sizeof(int), number_of_tokens, f);
	fwrite(match_lengths, sizeof(int), number_of_tokens, f);
	fwrite(mismatches, sizeof(int), number_of_tokens, f);

	fclose(f);


	// Creating altered filename for output (csv)
	char numstr2[21];
	char* new_file_name2 = in_PGM_filename_Ptr + '1';
	// char* new_file_name2 = in_PGM_filename_Ptr + itoa(searching_buffer_size, numstr2, 10);
	strcat(new_file_name2, ".offsets.csv");

	char numstr3[21];
	char* new_file_name3 = in_PGM_filename_Ptr + '1';
	// char* new_file_name3 = in_PGM_filename_Ptr + itoa(searching_buffer_size, numstr3, 10);
	strcat(new_file_name3, ".lengths.csv");

	f = fopen(new_file_name2, "w");
	FILE *f2 = fopen(new_file_name3, "w");

	// Writing offsets and mismatches to appropriate files
	for(int i = 0; i < number_of_tokens; i++){
		if(i != 0){
			fprintf(f, ",");
			fprintf(f2, ",");
		}
		fprintf(f, "%d", offsets[i]);
		fprintf(f, "%d", mismatches[i]);
	}

	fclose(f);
	fclose(f2);


	// Calculating the average
	*avg_offset_Ptr = 0.0;
	*avg_length_Ptr = 0.0;
	for(int i = 0; i < number_of_tokens; i++){
		*avg_offset_Ptr += offsets[i];
		*avg_length_Ptr += mismatches[i];
	}
	*avg_offset_Ptr /= number_of_tokens;
	*avg_length_Ptr /= number_of_tokens;


	// Calculating standard deviation
	*std_offset_Ptr = 0.0;
	*std_length_Ptr = 0.0;
	for(int i = 0; i < number_of_tokens; i++){
		*avg_offset_Ptr += pow(offsets[i] - *avg_offset_Ptr, 2);
		*avg_length_Ptr += pow(mismatches[i] - *avg_length_Ptr, 2);
	}
	*avg_offset_Ptr = sqrt(*avg_offset_Ptr / number_of_tokens);
	*avg_length_Ptr = sqrt(*avg_length_Ptr / number_of_tokens);


	// Clearing all freed memory
	free(offsets);
	free(match_lengths);
	free(mismatches);
	free(file_header);
	free(image);
}
