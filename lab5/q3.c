#include <stdio.h>

int main(void)
{
    float x = 3.14159265358979;
    printf("Output-01 3.14159265358979 \t displays %f\n", x);
    printf("Output-02 3.14159265358979 \t displays %1.1f\n", x);
    printf("Output-03 3.14159265358979 \t displays %1.2f\n", x);
    printf("Output-04 3.14159265358979 \t displays %3.3f\n", x);
    printf("Output-05 3.14159265358979 \t displays %4.4f\n", x);
    printf("Output-06 3.14159265358979 \t displays %4.5f\n", x);
    printf("Output-07 3.14159265358979 \t displays %09.3f\n", x);
    printf("Output-08 3.14159265358979 \t displays %-09.3f\n", x);
    printf("Output-09 3.14159265358979 \t displays %9.3f\n", x);
    printf("Output-10 3.14159265358979 \t displays %-9.3f\n", x);
    return 0;
}