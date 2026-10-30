#include <stdio.h>
#include <math.h>

void populate_readings(float readings[], FILE *fpi);

void hourave();

void dailymsd();

float monthhr();


int main(void)
{
    // Reading array, intialise to random capacity
    float readings[100];

    // Month arrays store day, 
    float april[31][3];
    float may[31][3];
    float june[31][3];

    FILE *fpi;
    fpi = open("proj2.txt", "r");

    populate_readings(readings, fpi);
}

void populate_readings(float readings[], FILE *fpi)
{

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