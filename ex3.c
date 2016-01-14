#include <stdio.h>

#define bitrev(type, dst, src) \
do { \
	int pos; \
	dst = 0; \
	for (pos = 0; pos < (sizeof(type) * 8); pos++) { \
		dst |= ((src) & (1 << pos)) >> pos << (sizeof(type) * 8 - pos); \
	} \
} while(0)
#define print_bit(type, c) \
do { \
	int pos; \
	for (pos = 0; pos < (sizeof(type) * 8); pos++) { \
		if (((c) >> (sizeof(type) * 8 - pos)) & 1) \
			putchar('1'); \
		else \
			putchar('0'); \
	} \
	putchar('\n'); \
} while (0)

int main()
{
	unsigned char c, c_dst;
	unsigned int number, number_dst;
	printf("Input char = ");
	scanf("%c", &c);
	bitrev(unsigned char, c_dst, c);
	print_bit(unsigned char, c);
	print_bit(unsigned char, c_dst);
	printf("Input hex number = 0x");
	scanf("%x", &number);
	bitrev(unsigned int, number_dst, number);
	print_bit(unsigned int, number);
	print_bit(unsigned int, number_dst);
	return 0;
}

