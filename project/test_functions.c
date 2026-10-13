#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int check_int(int *input)
{
    int scan_status = scanf("%d", input);
    if (scan_status == EOF)
    {
        return -1;
    }
    if (scan_status == 0)
    {
        while ((getchar()) != '\n');
        return 0;
    }
    return 1;
}

bool check_length(int input, int numlength)
{
    unsigned int counter = 0;
    if (input == 0)
    {
        counter++;
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

int get_digits_no(int *digits_no)
{
    while (true)
    {
        printf("Enter number of digits: ");
        int status = check_int(digits_no);
        if (status == 0)
        {   
            printf("Invalid. Please enter number of digits (0-9).\n");
            continue;
        }
        if (status == 1)
        {
            // Check range
            if (*digits_no >= 0 && *digits_no <= 9)
            {
                if (*digits_no == 0)
                {
                    printf("0 entered. Terminating program.\n");
                    return 0; 
                }
                return 1;
            }
            printf("Number of digits out of range (0-9).\n");
        }
        if (status == -1)
        {
            printf("EOF detected. Terminating program.\n");
            return -1;
        }
    }
}

int get_input_no(int *input_no, int digits_no)
{
    while (true)
    {
        printf("Enter n-digit number: ");
        int status = check_int(input_no);
        if (status == 0)
        {
            printf("Invalid. Please enter an integer.\n");
            continue;
        }
        if (status == 1)
        {
            if (check_length(*input_no, digits_no))
            {
                return 1;
            }
            printf("Number does not match specified length [%d]\n", digits_no);
        }
        if (status == -1)
        {
            printf("EOF detected. Terminating program.\n");
            return -1;
        }
    }   
}

int check_binary(int input_number, int digits_no, int output_array[], bool *is_binary)
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