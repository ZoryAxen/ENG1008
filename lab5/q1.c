#include <stdio.h>
#include <math.h>

int main (void)
{
    int x = 123;
    printf("Output-01 123 displays %d\n", x);
    printf("Output-02 123 displays %1d\n", x);
    printf("Output-03 123 displays %2d\n", x);
    printf("Output-04 123 displays %3d\n", x);
    printf("Output-05 123 displays %4d\n", x);
    printf("Output-06 123 displays %5d\n", x);
    printf("Output-07 123 displays %6d\n", x);
    printf("Output-08 123 displays %7d\n", x);
    printf("Output-09 123 displays %8d\n", x);
    printf("Output-10 123 displays %9d\n", x);
    printf("Output-11 123 displays %09d\n", x);
    printf("Output-11 123 displays %-9d\n", x);
    printf("Output-11 123 displays %-09d\n", x);
    return 0;
}
