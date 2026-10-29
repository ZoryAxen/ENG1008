#include <stdio.h>

int main (void)
{
    int a[10]={3, 5, 10, 9, 4, 5, 6, 8, 8, 9};
    int *iptr = a;
    for (int i = 0; i < 10; i++)
    {
        iptr[i] *= 3;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%i\t", a[i]);
    }
}