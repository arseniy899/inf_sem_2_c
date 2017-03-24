#include <stdio.h>
float sqr(float square)
{
    float root=square/3;
    int i;
    if (square <= 0) return 0;
    for (i=0; i<32; i++)
        root = (root + square / root) / 2;
    return root;
    
}
void main()
{
    printf("%f",sqr(15));
    printf("Calculating roots: ax^2+bx+c=0\n<a> <b> <c>\n");
    float a = 0, b= 0, c=0;
    scanf("%f %f %f",&a,&b,&c);
    float desc = sqr(b*b) -(4*a*c);
    //printf("desc=%f,%f,%f\n",desc, (b*b),(4*a*c));
    if(desc<0)
        printf("Error: no real roots");
    else if(desc==0)
        printf("x=%f\n",(b*(-1)-desc)/(2*a));
    else
        printf("x1=%f\nx2=%f\n",(b*(-1)-desc)/(2*a),(b*(-1)+desc)/(2*a));
}
