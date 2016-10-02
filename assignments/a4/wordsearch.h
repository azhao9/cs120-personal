/* wordsearch.h
 *
 * Aleck Zhao
 * 30 September 2016
 *
 * Headers for functions needed for a word-search puzzle solver
 *
 * Scaffolding for CS120-F16, A4 - put function prototypes here
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
void read_word(char word[]);
