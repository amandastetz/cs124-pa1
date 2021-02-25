#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double values[] = { 88, 56, 100, 2, 25 };

int compare (const void * a, const void * b)
{
    if (*(double*)a > *(double*)b) return 1;
    else if (*(double*)a < *(double*)b) return -1;
    else return 0;
}

int main()
{
    int n;

    printf("Before sorting the list is: \n");
    for( n = 0 ; n < 5; n++ )
    {
        printf("%.2f ", values[n]);
    }

    printf("\n\n");

    qsort(values, 5, sizeof(double), compare);

    printf("\nAfter sorting the list is: \n");
    for( n = 0 ; n < 5; n++ )
    {
        printf("%.2f ", values[n]);
    }

    printf("\n\n");

    return(0);
}