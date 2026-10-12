#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int check_int(int *input);
bool check_length(int input, int numlength);

int main(void)
{
    int  sum = 0, binary_multiplier = 1, digits_no, input_number, remainder;
    bool is_binary = true;
    
    char sign[4];
    int output_number[10];
    
    while (true)
    {
        printf("Enter number of digits: ");
        int status = check_int(&digits_no);
        if (status == 0)
        {   
            printf("Invalid. Please enter number of digits (0-9).\n");
            continue;
        }
        if (status == 1)
        {
            if (digits_no >= 0 && digits_no <=9)
            {
                break;
            }
            printf("Number of digits out of range (0-9).\n");
        }
        if (status == -1)
        {
            printf("EOF detected. Terminating program.\n");
            return 0;
        }
    }
    if (digits_no == 0)
    {
        printf("0 entered. Terminating program.\n");
        return 0;
    }
    while (true)
    {
        printf("Enter n-digit number: ");
        int status = check_int(&input_number);
        if (status == 0)
        {
            printf("Invalid. Please enter an integer.\n");
            continue;
        }
        if (status == 1)
        {
            if (check_length(input_number, digits_no))
            {
                break;
            }
            printf("Number does not match specified length [%d]\n", digits_no);
        }
        if (status == -1)
        {
            printf("EOF detected. Terminating program.\n");
            return 0;
        }
    }   
    if (input_number >= 0)
    {
        strcpy(sign, "[+]");
    }
    if (input_number < 0)
    {
        strcpy(sign, "[-]");
        input_number *= -1;
    }
    remainder = input_number;
    for (int i = digits_no - 1; i >= 0; i--)
    {
        int output_digit = remainder % 10;
        output_number[i] = output_digit;
        sum += output_digit * binary_multiplier;
        remainder = remainder / 10;
        if (output_digit != 0 && output_digit != 1)
        {
            is_binary = false;
        }
        binary_multiplier *= 2;
    }
    printf("Final output: %s", sign);
    for (int i = 0; i < digits_no; i++)
    {
        printf("%2d", output_number[i]);
    }
    printf("\n");
    if (is_binary)
    {
        printf("The decimal equivalent is %s%d", strcmp(sign, "[+]") ? "-" : "", sum);
    }
}


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
    if (counter == numlength)
    {
        return true;
    } 
    else 
    {
        return false;
    }
}
