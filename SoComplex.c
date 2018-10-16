/*
 * An extremely complex and difficult way to print Hello World /s
 */

#include <stdio.h>

int main() {
	char* str = "Hello World!\n";
	char* ptr = str;
	while (*ptr != '\0') {
		putchar(*ptr);
		ptr++;
	}
	return 0;
}
