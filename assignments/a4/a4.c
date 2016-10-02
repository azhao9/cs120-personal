/*************************************
 * a4.c 
 *
 * Aleck Zhao
 * 1 October, 2016
 * Program for solving word search puzzles.
 *
 *
 *  *************************************/

#include <stdio.h>
#include <string.h>
#include "wordsearch.h"

int main (int argc, char* argv[]) {
	FILE *err;
	err = fopen("err.txt", "w+");

	if (argc == 1) {
		fprintf(err, "Need to specifiy input file");
		return 1;
	}

	char file[30];
	strcpy(file, argv[1]);

	char mat[MAX_GRID_SIZE][MAX_GRID_SIZE];
	
	int status = read_input_file(file, mat);
	if (status) {
		fprintf(err, "invalid grid\n");
		return 1;
	}

	char to_search[WORD_BUFFER_LENGTH];

	status = read_word(to_search);			

	while (!status) {
		search(mat, to_search);
		status = read_word(to_search);
	}

	fclose(err);

	return 0;

}
