#include <stdio.h>

void swap(float *a, float *b)
{
    float *t = a;
    a= b;
    b = a;
}
int main(int argc, char*argv[])
{
	float beg, end, step;
	printf("Converting Celcius to Farengates\nEnter begining temp, end temp and step\r\n<beg> <end> <step>\r\n");
	scanf("%f %f %f",&beg,&end,&step);
	if(beg>end)
	 swap(&beg, &end);
	for(float i= beg; i<end;i+=step)
		printf("%.2f°C-> %.2f°F\n",i,((i*1.8)-32));
	return 0;
}
