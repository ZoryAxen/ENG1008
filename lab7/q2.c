#include <stdio.h>

int main(void)
{
    float array[10];

    for (int i = 0; i < 10; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%f", &array[i]);
    }

    float largest = array[0];
    for (int i = 0; i < 10; i++)
    {
        if(array[i] > largest)
        {
            largest = array[i];
        }
    }
    
    for (int i = 0; i < 10; i++)
    {
        printf("Number %d: %.1f \n", i, array[i]);
    }
    printf("Largest Number: %.f", largest);
}