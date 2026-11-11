#include <stdio.h>

float findLargest(float values[]);

int main(void)
{
    float values[] = {0.2, 0.1, 0.4, 0.5, 0.3};

    float largest = findLargest(values);

    printf("%.1f", largest);
}

float findLargest(float values[])
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
    return largest;
}