#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void populate_readings(float readings[], FILE *fpi);

void hourave();

void dailymsd();

float monthhr();


int main(void)
{
    // Reading array, intialise to random capacity
    float *readings = malloc(sizeof(float) * 100);

    // Month arrays store day, 
    float april[31][3];
    float may[31][3];
    float june[31][3];

    FILE *fpi;
    fpi = fopen("proj2.txt", "r");

    populate_readings(readings, fpi);

}

void populate_readings(float readings[], FILE *fpi)
{
    int count = 0;
    int capacity = 100;
    float value;
    float *temp;

    while(fscanf(fpi, "%f", &value) == 1)
    {
        readings[count] = value;
        count++;
        if (count == capacity)
        {
            capacity += 100;
            temp = realloc(readings, sizeof(float) * capacity);
            if (temp != NULL)
            {
                readings = temp;
            }
        }
    }
}

void hourave()
{

}

void dailymsd()
{

}

float monthhr()
{

}