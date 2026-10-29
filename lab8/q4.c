#include <stdio.h>

int main(void)
{
    int a = 100;
    int *iptr = &a;
    *iptr = 200;
    printf("%i\n", a);
    a = 250;
    printf("%i\n", a);
}