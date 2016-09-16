#include <stdio.h>
#define LENGTH 5

int main() {
	
	int ra[LENGTH];
	int ra2[LENGTH];

	printf("Enter 5 integers\n");

	scanf("%d %d %d %d %d", &(ra[0]), &(ra[1]), &(ra[2]), &(ra[3]), &(ra[4]));

	int sum = 0;

	for (int i = 0; i < LENGTH; i++) {
		sum += ra[i];
	}

	float avg = (float)sum/LENGTH;

	printf("The average is %f\n", avg);

	printf("The elements greater than the average are: ");

	for (int i = 0; i < LENGTH; i++) {
		if (ra[i] > avg) {
			printf("%d ", ra[i]);
		}
	}
	printf("\n");

	// index for second array
	int index = 0;

	for (int i = 0; i < LENGTH; i++) {
		if (ra[i] > avg) {
			ra2[index] = ra[i];
			index ++;
		}
	}

	printf("The values in the secondary array are: ");

	for (int i = 0; i < index; i++) {
		printf("%d ", ra2[i]);
	}

	printf("\n");

	return 0;


}

