#include <stdio.h>
#include <math.h>

void multiply (unsigned int n);

int main(void) 
{
    unsigned int num;

    while (1)
    {
        printf("Enter a number between 2 to 100: ");
        scanf("%u", &num);
        if (num < 2 || num > 100)
        {
            printf("Sorry, number must be between 2 to 100");
            break;
        } else 
        {
            multiply(num);
        }
    }   
    return 0;
}

void multiply (unsigned int n)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            printf("%9u", n*(i*10+j));
            if (j == 10)
            {
                printf("\n");
            }
        }
    }
}
