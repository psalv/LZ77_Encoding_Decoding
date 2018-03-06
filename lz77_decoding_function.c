#include "lz77_decoding_function.h"


// Save a value based on 1D number in 2D PGm image
void save_pgm_image_value(struct PGM_Image* image, int pos, unsigned char value){
	image->image[(int)floor(pos / image->width)][pos % image->width] = value;
}

// Using a single integer position, determine the character referenced in the pgm image
unsigned char get_pgm_image_value_(struct PGM_Image* image, int pos){
	return image->image[(int)floor(pos / image->width)][pos % image->width];
}

void Decode_Using_LZ77(char *in_compressed_filename_Ptr){

	/*** READING THE COMPRESSED FILE ***/

	FILE *f = fopen(in_compressed_filename_Ptr, "rb");

	// Reading the header
	struct header* file_header = malloc(sizeof(struct header));
	fread(file_header, sizeof(struct header), 1, f);

	// Retrieving relevant values from the header
	int number_of_tokens = file_header->number_of_tokens;

	// Creating a PGM image to populate
	struct PGM_Image* image = malloc(sizeof(struct PGM_Image));
	create_PGM_Image(image, file_header->width, file_header->height, file_header->max_gray_value);

	free(file_header);

	// Retrieving the tokens
	int* offsets = malloc(sizeof(int) * number_of_tokens);
	int* match_lengths = malloc(sizeof(int) * number_of_tokens);
	int* mismatches = malloc(sizeof(int) * number_of_tokens);

	fread(offsets, sizeof(int), number_of_tokens, f);
	fread(match_lengths, sizeof(int), number_of_tokens, f);
	fread(mismatches, sizeof(int), number_of_tokens, f);

	fclose(f);


	/*** DECOMPRESSING THE IMAGE ***/

	int cur_pos = 0;
	for(int i = 0; i < number_of_tokens; i++){
		for(int j = offsets[i]; j > offsets[i] - match_lengths[i]; j--){
			save_pgm_image_value(image, cur_pos, get_pgm_image_value_(image, cur_pos - j));
			cur_pos++;
		}
		save_pgm_image_value(image, cur_pos, mismatches[i]);
		cur_pos++;
	}


	/*** SAVING THE IMAGE ***/

	char new_file_name[100];
	sprintf(new_file_name, "%s.pgm", in_compressed_filename_Ptr);
	save_PGM_Image(image, new_file_name, 1);

	free(offsets);
	free(match_lengths);
	free(mismatches);
	free(image);
}
