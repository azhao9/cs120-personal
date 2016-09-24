#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void six() {
	int i;

	for (i=0; i<100; i++) {
		while (i % 10) {
			i++;
		}
		printf("%d", i);
	}
}

void one() {
	double x = 3.1415926535;
	for (int i = 0; i < 8; i++) {
		int y = x;
		printf("%d", y);
		x -= y;
		x *= 10;
	}
}

void two() {
	int i = 0;
	int j = 1;
	int k = -1;
	bool a = true;
	bool b = false;

	if (b = true)
		printf("1");
	if (j || (a = false))
		printf("2");

	if (i || a)
		printf("3");
	else
		printf("4");
		printf("5");

	if (j == k) {
		printf("6");
	} else if (b && k) {
		printf("7");
	} else {
		printf("8");
	}

	for (i = 0; i < 5; i++);
	{
		j++;
	}

	if (i > j) {
		printf("9");
	}
}

void three() {
	int y = 7;
	printf("%d\n", y);

	for(int x = 0; x < 10; x++) {
		int y = x * 2;
		printf("%d ", y);
	}

	printf("\n%d\n", y);
}

void four() {
	char str[10] = "strange";
	int len = strlen(str);
	printf("%d\n", len);

	for (int i = 2; i < len - 2; i++) {
		printf("%c", str[len-i]);
	}
}

int thing1(int i) {
		static int j = 5;
		j += i;
		i = j * 2;
		return i;
	}

	int thing2(int x, int y) {
		int z = thing1(x) + thing1(y) + x + y;
		return z;
	}

int main() {
	// six();
	// one();
	// two();
	// three();
	// four();
	
	int a = 2;
	int b = 5;
	printf("a=%d, b=%d, thing2(a, b)=%d", a, b, thing2(a, b));

	return 0;
}
