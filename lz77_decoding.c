#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#include "lz77_decoding_function.h"

int main(int argc, char *argv[]){

	if(argc != 2){
		printf("Please ensure you have entered two arguments. You entered: %d\n", argc - 1);
		exit(0);
	}

	if(access(argv[1], F_OK) == -1){
		printf("Please ensure you have entered a valid file.\n");
		exit(0);
	}

	clock_t time = clock();

	Decode_Using_LZ77(argv[1]);

    time = clock() - time;
    printf("\nDecompression Time:             %ld ms\n\n", (time * 1000) / CLOCKS_PER_SEC);

	return 0;
}
