#include <stdio.h>
#include <stdarg.h>
#include <math.h>

#define MAXNUM 3

struct point {
	double x;
	double y;
};

struct distance {
	double min;
	double max;
	double avg;
};

void pminmaxavg(int num, struct distance *distp, ...);

int main()
{
	struct distance result;
	struct point p[MAXNUM];
	p[0].x = 1.2;
	p[0].y = 0.4;
	p[1].x = -1.8;
	p[1].y = -2.4;
	p[2].x = 3.5;
	p[2].y = -2.9;
	pminmaxavg(MAXNUM, &result, p[0], p[1], p[2]);
	printf("min = %f\n", result.min);
	printf("max = %f\n", result.max);
	printf("avg = %f\n", result.avg);
	return 0;
}

void pminmaxavg(int num, struct distance *distp, ...) {
	int i;
	struct point buf;
	double dist;
	va_list va_ptr;

	va_start(va_ptr, distp);
	
	buf = va_arg(va_ptr, struct point);
	distp->min = distp->max = distp->avg
		= sqrt(buf.x * buf.x + buf.y * buf.y);

	for (i = 1; i < num; i++) {
		buf = va_arg(va_ptr, struct point);
		dist = sqrt(buf.x * buf.x + buf.y * buf.y);
		distp->avg += dist;
		if (distp->min > dist)
			distp->min = dist;
		if (distp->max < dist)
			distp->max = dist;
	}

	va_end(va_ptr);

	distp->avg /= num;
}

