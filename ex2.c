#include <stdio.h>
#include <stdlib.h>

#define LENGTH_STR 80

char *mystrstr(const char *s1, const char *s2);

int main()
{
	char s1[LENGTH_STR], s2[LENGTH_STR], *str;
	printf("Input String 1: ");
	scanf("%s", s1);
	printf("Input String 2: ");
	scanf("%s", s2);
	str = mystrstr(s1, s2);
	if (str == NULL) {
		fprintf(stderr, "%s was not found in %s.\n", s2, s1);
		exit(1);
	} else {
		printf("%s\n", str);
	}
	return 0;
}

char *mystrstr(const char *s1, const char *s2)
{
	int i, j;
	for (i = 0; s1[i] != '\0'; i++) {
		if (s1[i] == *s2) {
			for (j = 0; ; j++) {
				if (s2[j] == '\0') {
					return s1 + i;
				} else if (s1[i + j] != s2[j]){
					break;
				}
				if (s1[i + j] == '\0') {
					break;
				}
			}
		}
	}
	return NULL;
}

