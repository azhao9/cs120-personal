/* wordsearch.c
 *
 * Aleck Zhao
 * 30 September 2016
 *
 * Functions needed for a word-search puzzle solver.
 *
 * Scaffolding for CS120-F16, A4 - make at least 4 functions
 */

#include "wordsearch.h"
#include <ctype.h>

int read_input(char file[], char mat[MAX_GRID_SIZE][MAX_GRID_SIZE]) {

	// initializes matrix with null terminating characters
	for (int r = 0; r < MAX_GRID_SIZE; r++) {
		for (int c = 0; c < MAX_GRID_SIZE; c++) {
			mat[r][c] = '\0';
		}
	}

	FILE *filehandle;
	char cur;

	// this open is to count the number of columns in the first row
	// returns 1 if grid has 0 or more than 10 columns
	filehandle = fopen(file, "r");	

	int col_count = 0;

	// loop to 11 to see if 11th char is also a letter
	for (int i = 0; i < MAX_GRID_SIZE + 1; i++) {
		cur = fgetc(filehandle);
		if (cur != '\n') {
			if (!isspace(cur)) {
				col_count++;
			}
		} else {
			break;
		}
	}	
	
	// if 11th char is letter, then 11+ columns, invalid
	if (col_count == 0 || col_count == 11) {
		return 1;
	}

	fclose(filehandle);

	// this open is to check if all rows and columns have the same number of letters
	filehandle = fopen(file, "r");



	// actually reads input
	for (int r = 0; r < col_count; r++) {
		for (int c = 0; c < col_count; c++) {
			cur = fgetc(filehandle);
			mat[r][c] = cur;
		}

		// this passes over the newline
		cur = fgetc(filehandle);
	}

	return 0;
}





