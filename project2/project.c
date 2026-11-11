#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void populate_readings(float readings[], FILE *fpi);

void hourave(float readings[], float month[][16], int offset);

void dailymsd(float readings[], float month[][16], int offset);

float monthhr(float month[][16], int hour);


int main(void)
{
    // 1D reading array to store all data
    float readings[5040];

    // Month arrays store
    float april[30][16];
    float may[30][16];
    float june[30][16];

    FILE *fpi;
    fpi = fopen("proj2.txt", "r");

    populate_readings(readings, fpi);
    fclose(fpi);

    // Function calls
    hourave(readings, april, 0);
    hourave(readings, may, 1680);
    hourave(readings, june, 3360);
    dailymsd(readings, april, 0);
    dailymsd(readings, may, 1680);
    dailymsd(readings, june, 3360);

    // IO
    for (int month = 0; month < 3; month++)
    {
        printf("%s Temperature\n", month == 0 ? "April" : (month == 1 ? "May" : "June"));
        for (int day = 0; day < 30; day++)
        {
            printf("Day %d: \n", day);
            if (month == 0)
            {
                for (int hour = 0; hour < 14; hour++)
                {
                    printf("Temp: %-6.2f", april[day][hour]);
                }
            } else if (month == 1)
            {
                for (int hour = 0; hour < 14; hour++)
                {
                    printf("Temp: %-6.2f", may[day][hour]);
                }
            } else 
            {
                for (int hour = 0; hour < 14; hour++)
                {
                    printf("Temp: %-6.2f", june[day][hour]);
                }
            }
            printf("Daily mean: %-6.2f  Daily sd: %-6.2f", april[day][14], april[day][15]);
            printf("\n");
        }
        printf("%-6.2f", monthhr(april, 1));
        printf("\n");
    }
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

void hourave(float readings[], float month[][16], int offset)
{
    for (int day = 0; day < 30; day++)
    {
        for (int hour = 0; hour < 14; hour++)
        {
            float sum = 0.0f;
            float houraverage = 0.0f;
            for (int interval = 0; interval < 4; interval++)
            {   
                sum += readings[offset];
                offset++;
            }
            houraverage = sum / 4.0f;
            month[day][hour] = houraverage;
        }
    }
}

void dailymsd(float readings[], float month[][16], int offset)
{
    for (int day = 0; day < 30; day++)
    {
        float sum = 0.0f;
        float mean = 0.0f;
        for (int i = 0; i < 56; i++)
        {
            sum += readings[offset];
            offset++;
        }
        mean = sum / 56.0f;
        month[day][14] = mean;

        float squared_diff_sum = 0.0f;
        for (int i = 0; i < 56; i++)
        {
            float diff = readings[offset - (i + 1)];
            squared_diff_sum += diff * diff;
        }

        float sd = sqrt(squared_diff_sum / 56.0f);
        month[day][15] = sd;
    }
}

float monthhr(float month[][16], int hour)
{
    float monthhr_sum = 0.0f;
    for (int day = 0; day < 30; day++)
    {
        monthhr_sum += month[day][hour];
    }
    return monthhr_sum / 30.0f;
}