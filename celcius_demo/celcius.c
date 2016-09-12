/* celcius.c
 * A program for CS 120, fall 16
 * designed to print a conversion table for temperatures
 *
 * Author: Aleck Zhao
 * Date: 2016-09-12
 */

#include <stdio.h>

/* 
 * C = (F - 32) * 5 / 9
 * F = (C * 9 / 5) + 32
 */
int main()
{
	int tempFrom;
	int tempTo;

	int tempLow = 20;
	int tempHigh = 100;
	int stepSize = 20;
	
	tempFrom = tempLow;
	while (tempFrom <= tempHigh) {
		tempTo = (tempFrom - 32) * 5 / 9; // convert from F to C
		printf("%d F = %d C\n", tempFrom, tempTo);
		tempFrom = tempFrom + stepSize;
	}

	return 0;
}


