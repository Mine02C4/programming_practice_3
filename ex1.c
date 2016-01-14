#include <stdio.h>

int my_isxdigit(int c);

int main()
{
	char c;
	int xdigit = 0, non_xdigit = 0;
	while ((c = getchar()) != EOF) {
		if (my_isxdigit(c)) {
			xdigit++;
		} else {
			non_xdigit++;
		}
	}
	printf("xdigit = %d\n", xdigit);
	printf("non_xdigit = %d\n", non_xdigit);
	return 0;
}

int my_isxdigit(int c)
{
	if ((c >= 'A' && c <= 'F') ||
			(c >= 'a' && c <= 'f') ||
			(c >= '0' && c <= '9')) {
		return 1;
	} else {
		return 0;
	}
}

