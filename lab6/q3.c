#include <stdio.h>

void findLargest(float values[]);
void tripleFloat(float values[]);

int main(void)
{
    float values[] = {0.2, 0.1, 0.4, 0.5, 0.3};

    findLargest(values);
    tripleFloat(values);
    printf("Original: ");
    for (int i=0; i < 5; i++)
    {
        printf("%.1f\t", values[i]);
    }
}

void findLargest(float values[])
{
    float largest = 0;
    float current = 0;

    for (int i = 0; i < 5; i++)
    {
        current = values[i];
        if (current > largest)
        {
            largest = current;
        }
    }
    printf("Largest: %.1f\n", largest);
}

void tripleFloat(float values[])
{
    printf("Triple: ");
    for (int i=0; i < 5; i++)
    {
        printf("%.1f\t", values[i] * 3);
    }
    printf("\n");
}

