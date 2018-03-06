#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#include "libpnm.h"
#include "lz77_encoding_function.h"

#ifndef _DECODE_USING_LZ77__
#define _DECODE_USING_LZ77__

unsigned char get_pgm_image_value_(struct PGM_Image* image, int pos);

void save_pgm_image_value(struct PGM_Image* image, int pos, unsigned char value);

void Decode_Using_LZ77(char *in_compressed_filename_Ptr);

#endif
