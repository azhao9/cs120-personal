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

/* Takes an input file name, and given a matrix to read letters into
 * Performs various checks to determine if grid is valid
 */
int read_input_file(char file[], char mat[MAX_GRID_SIZE][MAX_GRID_SIZE]) {

	FILE *filehandle;
	char cur;

	// this open is to count the number of columns in the first row
	//
	filehandle = fopen(file, "r");	

	int col_count = 0;

	cur = fgetc(filehandle);
	
	if (cur == EOF) {
		return 1;
	}

	while (cur != '\n') {
		// if line has any "holes"
		if (isspace(cur)) {
			return 1;
		} else {
			col_count++;
			cur = fgetc(filehandle);
		}
	}

	// 0 columns or more than 10 columns
	if (col_count ==0 || col_count > 10) {
		return 1;
	}

	printf("cols: %d\n", col_count);

	fclose(filehandle);

	// this open is to check if same number of rows as cols
	filehandle = fopen(file, "r");

	int row_count = 0;
	cur = fgetc(filehandle);

	while (cur != EOF) {
		if (cur == '\n') {
			row_count++;
		}
		cur = fgetc(filehandle);
	}

	printf("rows: %d", row_count);

	if (row_count != col_count) {
		return 1;
	}

	fclose(filehandle);

	// this open is to check if each row has same number of letters
	filehandle = fopen(file, "r");

	int row_letters = 0;
	cur = fgetc(filehandle);

	while (cur != EOF) {
		if (cur != '\n') {
			// counts number of letters in row
			row_letters++;
		} else {
			if (row_letters != col_count) {
				return 1;
			} else {
				// reset counter, start next row
				row_letters = 0;
			}
		}
		cur = fgetc(filehandle);
	}

	fclose(filehandle);

	// this open reads input into matrix
	filehandle = fopen(file, "r");

	// initializes matrix with null terminating characters
	for (int r = 0; r < MAX_GRID_SIZE; r++) {
		for (int c = 0; c < MAX_GRID_SIZE; c++) {
			mat[r][c] = '\0';
		}
	}

	for (int r = 0; r < row_count; r++) {
		for (int c = 0; c < col_count; c++) {
			cur = fgetc(filehandle);
			mat[r][c] = cur;
		}

		// this passes over the newline
		cur = fgetc(filehandle);
	}

	fclose(filehandle);

	return 0;
}

/* Reads input from stdin
 * Truncates words that are longer than the maximum length
 * Stops word when empty space is encountered
 */
void read_word(char word[]) {
	
	char ch;
	int wordLen = 0;

	while ((ch = getchar()) != EOF && !isspace(ch)) {
		if (wordLen + 1 >= WORD_BUFFER_LENGTH) {
			word[WORD_BUFFER_LENGTH - 1] = '\0';
		} else {
			word[wordLen++] = ch;
		}
	}

	word[wordLen] = '\0';

	return 0
}



