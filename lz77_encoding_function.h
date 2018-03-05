#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include "libpnm.h"

#ifndef _ENCODE_USING_LZ77__
#define _ENCODE_USING_LZ77__

struct header{
	unsigned int max_offset;
	int number_of_tokens;
	int width;
	int height;
	int max_gray_value;
};

int max(int a, int b);

unsigned char get_pgm_image_value(struct PGM_Image* image, int pos);

int find_number_of_matches(struct PGM_Image* image, int match_pos, int text_pos, int total);

void Encode_Using_LZ77(char *in_PGM_filename_Ptr, unsigned int searching_buffer_size, 
	float *avg_offset_Ptr, float *std_offset_Ptr, float *avg_length_Ptr, 
	float *std_length_Ptr);

#endif