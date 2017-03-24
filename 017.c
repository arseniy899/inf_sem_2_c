
#include <stdio.h>
void main()
{
    double arr[256];
    double max = -999999.0, min= 999999.0;
    printf("Finding difference between max and min in double array. \nEnter size of array:");
    int num = 0;
    scanf("%i",&num);
    printf("Enter each of them one by one:\n");
    for(int i=0;i<num;i++)
        scanf("%lf",&arr[i]);
    for(int i=0;i<num;i++)
    {
        double n = arr[i];
        if(max<n)
            max=n;
        if(min>n)
            min = n;
    }
    printf("\nMAX=%.2lf,min=%.2lf,diff=%.4lf",max,min,(max-min));
}

