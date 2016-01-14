#include <stdio.h>
#include <stdlib.h>

void tail(int num, FILE *fp);

int main(int argc, char *argv[])
{
	FILE *fp;
	int num;
	if (argc == 2 && *argv[1] != '-') {
		if ((fp = fopen(argv[1], "r")) == NULL) {
			fprintf(stderr, "Cannot open file %s\n", argv[1]);
			exit(1);
		}
		tail(10, fp);
		fclose(fp);
	} else if (argc == 3 && *argv[1] == '-' && *argv[2] != '-') {
		num = atoi(argv[1] + 1);
		if ((fp = fopen(argv[2], "r")) == NULL) {
			fprintf(stderr, "Cannot open file %s\n", argv[2]);
			exit(1);
		}
		tail(num, fp);
		fclose(fp);
	} else {
		fprintf(stderr, "Usage: ex4 [-n] file\n");
		exit(0);
	}
	return 0;
}

void tail(int num, FILE *fp)
{
	int i, offset;
	char **lines;
	if ((lines = (char **) malloc(sizeof(char *) * num)) == NULL) {
		fprintf(stderr, "Cannot allocate memory!\n");
		exit(1);
	}
	for (i = 0; i < num; i++) {
		if ((lines[i] = (char *) malloc(sizeof(char) * 80)) == NULL) {
			fprintf(stderr, "Cannot allocate memory!\n");
			exit(1);
		}
		*lines[i] = '\0';
	}
	for (i = 0; i < num; i = (i + 1) % num) {
		if (fgets(lines[i], 80, fp) == NULL) {
			break;
		}
	}
	offset = i;
	if (*lines[i] != '\0') {
		printf("%s", lines[i]);
	}
	free(lines[i]);
	i = (i + 1) % num;
	for (; i != offset; i = (i + 1) % num) {
		if (*lines[i] != '\0') {
			printf("%s", lines[i]);
		}
		free(lines[i]);
	}
	free(lines);
}

