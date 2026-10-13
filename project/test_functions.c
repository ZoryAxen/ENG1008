#include <stdbool.h>
#include <stdlib.h>

bool check_length(int input, int numlength)
{
    unsigned int counter = 0;
    input = abs(input);

    if (input == 0)
    {
        counter = 1;
    }
    else 
    {
        while (input != 0)
        {
            input = input / 10;
            counter++;
        }  
    }  
    return (counter == numlength);
}

int process_binary(int input_number, int digits_no, int output_array[], bool *is_binary)
{
    int sum = 0;
    int binary_multiplier = 1;
    *is_binary = true;
    
    if (input_number < 0)
    {
        input_number *= -1;
    }
    
    int remainder = input_number;
    for (int i = digits_no - 1; i >= 0; i--)
    {
        int output_digit = remainder % 10;
        output_array[i] = output_digit;
        sum += output_digit * binary_multiplier;
        remainder = remainder / 10;
        
        if (output_digit != 0 && output_digit != 1)
        {
            *is_binary = false;
        }
        binary_multiplier *= 2;
    }
    return sum;
}