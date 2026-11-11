#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void populate_readings(float readings[], FILE *fpi);

void hourave(float readings[], float month[][]);

void dailymsd();

float monthhr();


int main(void)
{
    // 1D reading array to store all data
    float readings[5040];

    // Month arrays store
    float april[30][3];
    float may[30][3];
    float june[30][3];

    FILE *fpi;
    fpi = fopen("proj2.txt", "r");

    populate_readings(readings, fpi);
    printf("%f", readings[0]);
    fclose(fpi);

}

void populate_readings(float readings[], FILE *fpi)
{
    int count = 0;
    int capacity = 5040;
    float value;

    while(fscanf(fpi, "%f", &value) == 1)
    {
        if (count == capacity)
        {
            printf("Data set exceeds storage limits!\n");
            break;
        }
        readings[count] = value;
        count++;
    }
}

void hourave(float readings[], float month[][])
{
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            
        }
    }

}

void dailymsd()
{

}

float monthhr()
{

}