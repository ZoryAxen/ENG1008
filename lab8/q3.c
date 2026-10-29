#include <stdio.h>

void average_temp(float readings[3][5]);

int main(void)
{
   float readings[3][5]= {24.0,25.5,26.5,26.0,23.5,23.9,24.9,26.3,25.5,23.8,24.2,25.8,26.3,25.7,24.1};

   average_temp(readings);
}

void average_temp(float readings[3][5])
{
    float average = 0;
    float total = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            total += readings[i][j];
        }
    }
    average = total / 15;
    printf("%.1f", average);
}                          