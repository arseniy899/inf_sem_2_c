#include <stdio.h>
#include <math.h>

void getDiffern(float x1,float x2,float h)
{
    float dif3 = 0,xi=x1;
    int i = 0;
    printf("%f\n",1/(2*h)*(-3*x1*x1+4*pow(x1+h,2)-pow(x1+2*h,2)));
    printf("%f\n",1/(2*h)*(pow(x1+2*h,2)-x1*x1));
    while(xi<=x2)
	{
		printf("%f\n",1/(2*h)*(xi*xi-4*pow(xi+h,2)+3*pow(xi+2*h,2)));
		xi+=h;
	}
}
int main(void)
{
    double beg, end, step;
    printf("Differenting by 3 points. \n Function set: y=x^2.\nEnter <begining> <end> <step>: \n");
    scanf("%lf %lf %lf",&beg, &end, &step);
    getDiffern(beg, end, step);
    return 0;
}