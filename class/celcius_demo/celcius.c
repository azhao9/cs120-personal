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
	float tempFrom;
	float tempTo;

	int tempLow = 10;
	int tempHigh = 50;
	int stepSize = 10;

	char scaleTo;

	printf("Enter 'f' for F to C, 'c' for C to F: ");
	scaleTo = getchar();

	tempFrom = tempLow;
	while (tempFrom <= tempHigh) {
		if (scaleTo == 'c') {
			printf("got c\n");
		} else if (scaleTo == 'f') {	
			printf("got f\n");
		} else {
			printf("bad input\n");
		}

		tempTo = (tempFrom - 32) * (5.0 / 9.0); // convert from F to C
		printf("%f F = %f C\n", tempFrom, tempTo);
		tempFrom = tempFrom + stepSize;
	}

	return 0;
}


