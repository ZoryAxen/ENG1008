#include <stdio.h>

#define SIZE 10

float findmax(float array[], int size);
void print1d(float array[], int size);

int main(void)
{
    float array[SIZE];
    float max;

    printf("Enter numbers: \n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("Number %d: ", i + 1);
        scanf("%f", &array[i]);
    }

    max = findmax(array, SIZE);
    print1d(array, SIZE);
    printf("Largest number:\n%.1f", max);
}

float findmax(float array[], int size)
{
    float max = array[0];
    for (int i = 0; i < size; i++)
    {
        if (max < array[i])
        {
            max = array[i];
        }
    }
    return max;
}

void print1d(float array[], int size)
{
    printf("Printing array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%.1f\n", array[i]);
    }
}