#include <stdio.h>
#include <string.h>

void backstr (char str[]) {
	int len = strlen(str);

	for (int i = len - 1; i >= 0; i--) {
		printf("%c", str[i]);
	}
	printf("\n");
}

int main() {
	char s[] = "string";

	backstr(s);

	return 0;

}


