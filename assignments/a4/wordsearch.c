/* wordsearch.c
 *
 * Aleck Zhao
 * 2 October, 2016
 *
 * Functions needed for a word-search puzzle solver.
 *
 *
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

	fclose(filehandle);

	// this open is to check if same number of rows as cols
	filehandle = fopen(file, "r");

	int row_count = 0;
	cur = fgetc(filehandle);

	while (cur != EOF) {
		if (cur == '\n') {
			row_count++;
		} else if (isspace(cur)) {
			return 1;
		}
		cur = fgetc(filehandle);
	}

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
			mat[r][c] = tolower(cur);
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
 * returns 1 if EOF or ctrl-D encountered, otherwise 0
 */
int read_word(char word[]) {
	
	char ch;
	int wordLen = 0;

	ch = tolower(getchar());
	if (ch == EOF) {
		return 1;
	} else {
		word[wordLen++] = ch;
	}

	while (!isspace(ch = tolower(getchar()))) {
		if (wordLen + 1 >= WORD_BUFFER_LENGTH) {
			word[WORD_BUFFER_LENGTH - 1] = '\0';
		} else {
			word[wordLen++] = ch;
		}
	}

	word[wordLen] = '\0';

	return 0;
}

/* Searches grid for a word in 4 directions
 * right, left, down, up
 * prints if word is not found
 */
void search(char mat[MAX_GRID_SIZE][MAX_GRID_SIZE], char word[]) {
	int d = search_direction(mat, word, 'D');
	int r = search_direction(mat, word, 'R');
	int l = search_direction(mat, word, 'L');
	int u = search_direction(mat, word, 'U');

	if (!(r || l || d || u)) {
		printf("\"%s\" - Not Found\n", word);
	}
}

/* Searches grid for a word, based on input direction
 * returns 1 if word is found, 0 if not found
 */
int search_direction(char mat[MAX_GRID_SIZE][MAX_GRID_SIZE], char word[], char direction) {
	// row and col increments
	int row_inc;
	int col_inc;

	// depends on specified search direction
	if (direction == 'U') {
		row_inc = -1;
		col_inc = 0;
	} else if (direction == 'D') {
		row_inc = 1;
		col_inc = 0;
	} else if (direction == 'R') {
		row_inc = 0;
		col_inc = 1;
	} else if (direction == 'L') {
		row_inc = 0;
		col_inc = -1;
	}

	int start_row;
	int start_col;
	int cur_row;
	int cur_col;

	// index in word to search
	int index = 0;

	// length of word
	int length = 0;

	// calculates length of word
	while (word[index] != '\0') {
		index++;
		length++;
	}

	char ch;
	int ever_found = 0;

	for (int r = 0; r < MAX_GRID_SIZE; r++) {
		for (int c = 0; c < MAX_GRID_SIZE; c++) {
			index = 0;
			int found = 0;
			int in_grid = 1;

			start_row = r;
			start_col = c;
			cur_row = r;
			cur_col = c;

			ch = mat[cur_row][cur_col];

			// reached end of grid
			if (ch == '\0') {
				continue;
			}

			while (ch == word[index] && !found && in_grid) {
				cur_row += row_inc;
				cur_col += col_inc;

				if (cur_row < MAX_GRID_SIZE && cur_col < MAX_GRID_SIZE) {
					ch = mat[cur_row][cur_col];
				} else {
					// no longer in grid, exit
					in_grid = 0;
				}

				index++;

				// found entire word
				if (index == length) {
					found = 1;
				}

			}

			if (found) {
				printf("Found \"%s\" at %d %d, %c\n", word, start_row, start_col, direction);
				ever_found = 1;
			}
		}
	}

	return ever_found;
}
