#include <stdio.h>
#include <math.h>
double getIntegralBySympson(double a,double b,int n)
{
    int  i = 1;
    double c=0.0,integral=0.0,sum = 0.0,sum_1 = 0.0,h=0.0;
    h=(b-a)/n;
	c = a;
	while(c<b)
	{
		c+=h;
		if(i%2!=0)
			sum+=2*c;
		else
			sum_1=sum_1+2*c;
		i++;
	}
	integral=h/3*(2*a+2*b+4*sum+2*sum_1);
    return integral;
}
int main(void)
{
    double beg, end;
    int dist;
    printf("Intergrating by Simpson's method. \n Using function: y=2x\n Enter: <begining> <end> <amount of distructions>");
    scanf("%lf %lf %i",&beg, &end, &dist);
    printf("\nResult: %lf\n",getIntegralBySympson(beg, end, dist));
    return 0;
}