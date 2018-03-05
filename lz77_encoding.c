#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#include "lz77_encoding_function.h"

int main(int argc, char *argv[]){

	if(argc != 3){
		printf("Please ensure you have entered two arguments. You entered: %d\n", argc - 1);
		exit(0);
	}

	if(access(argv[1], F_OK) == -1){
		printf("Please ensure you have entered a valid file.\n");
		exit(0);
	}

	unsigned int searching_buffer_size = atoi(argv[2]);
	if(argv[2][0] != '0' && searching_buffer_size == 0){
		printf("Please ensure you have entered a buffer size.\n");
		exit(0);
	}

	float avg_offset_Ptr, std_offset_Ptr, avg_length_Ptr, std_length_Ptr;

	clock_t time = clock();

    Encode_Using_LZ77(argv[1], searching_buffer_size, &avg_offset_Ptr, &std_offset_Ptr, 
    	&avg_length_Ptr, &std_length_Ptr);

    time = clock() - time;
    printf("Time taken to encode:             %ld ms\n", (time * 1000) / CLOCKS_PER_SEC);
    printf("Average offset:                   %f\n", avg_offset_Ptr);
    printf("Stand deviation of offset:        %f\n", std_offset_Ptr);
    printf("Average length of match:          %f\n", avg_length_Ptr);
    printf("Stand deviation of match length:  %f\n", std_length_Ptr);

	return 0;
}
