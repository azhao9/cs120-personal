/* wordsearch.h
 *
 * Aleck Zhao
 * 1 October, 2016
 *
 * Headers for functions needed for a word-search puzzle solver
 *
 */

#ifndef _CS120_SCAFFOLD_WORDSEARCH_H
#define _CS120_SCAFFOLD_WORDSEARCH_H

#include <stdio.h> // you'll need this if you want file handles as arguments 
#include <string.h> // using string library
#include <stdlib.h> // using standard library

#define MAX_GRID_SIZE 10 // constant for max grid size
#define WORD_BUFFER_LENGTH 11 // space for 10 "word" chars plus a null-termination

#endif

// function for reading input file into a matrix
int read_input_file(char file[], char mat[MAX_GRID_SIZE][MAX_GRID_SIZE]);

// reads stdin words
int read_word(char word[]);

// searches for a word in the grid
void search(char mat[MAX_GRID_SIZE][MAX_GRID_SIZE], char word[]);

// searches for a word by direction
int search_direction(char mat[MAX_GRID_SIZE][MAX_GRID_SIZE], char word[], char direction);
