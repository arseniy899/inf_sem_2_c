#include <stdio.h>

int main(int argc, char*argv[])
{
	float a = 0.0, b = 0.0, c = 0.0, d = 0.0;
	printf("Calculating imagery resistance.\n Enter resistances a+bi,c+di in such format: <a> <b> <c> <d>\n ");
	scanf("%f %f %f %f", &a, &b, &c, &d);
	printf("%.4f+i*%.4f", (c*c*a + c*a*a + c*b*b + a*d*d) / ((c + a)*(c + a) + (d + b)*(d + b)), 
						(c*c*b + a*a*d + d*d*b + d*b*b) / ((c + a)*(c + a) + (d + b)*(d + b)));
	return 0;
}