/**************************************
 * a4.c 
 *
 * Aleck Zhao
 * 30 September, 2016
 * Program for solving word search puzzles.
 *
 *
 * Scaffolding for CS120-F16, HW4 - fill in
 * main, but keep it short; my reference implementation
 * has about 20 lines of actual code in main (not counting
 * comments and whitespace).
 *************************************/

#include <stdio.h>
#include <string.h>
#include "wordsearch.h"

int main (int argc, char* argv[]) {
	char file[30];
	strcpy(file, argv[1]);

	char mat[MAX_GRID_SIZE][MAX_GRID_SIZE];

	
	int status = read_input(file, mat);
	if (status) {
		printf("invalid grid\n");
		return 1;
	}

	for (int r = 0; r < MAX_GRID_SIZE; r++) {
		for (int c = 0; c < MAX_GRID_SIZE; c++) {
			printf("%c ", mat[r][c]);
		}
		printf("\n");
	}

	return 0;

}
