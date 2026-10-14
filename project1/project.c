#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// BEGINNING OF PROTOTYPES
int check_int(int *input);
bool check_length(int input, int numlength);
int get_digits_no(int *digits_no);
int get_input_no(int *input_no, int digits_no);
void convert_binary(int input_no, int digits_no, char sign[], int output_no[], int *sum, bool *is_binary);
void print_results( char sign[], int digits_no, int output_no[], bool is_binary, int sum);
// END OF PROTOTYPES

// ENTRY POINT MAIN()
int main(void)
{
    int  sum = 0, digits_no, input_no;
    bool is_binary = true;
    
    char sign[4];
    int output_no[10];

    // Get number n
    int digit_status = get_digits_no(&digits_no);
    // Catch 0 (Sentinel value) or EOF & terminate program
    if (digit_status == 0 || digit_status == -1)
    {
        return 0;
    }

    // Get input number of n-digits
    int input_status = get_input_no(&input_no, digits_no);

    // Catch EOF & terminate program
    if (input_status == -1)
    {
        return 0;
    }

    // Calculate binary and output
    convert_binary(input_no, digits_no, sign, output_no, &sum, &is_binary);

    // Print results
    print_results(sign, digits_no, output_no, is_binary, sum);
}
// END OF MAIN()

// BEGINNING OF HELPER FUNCTIONS
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
    return (counter <= numlength);
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
            printf("Number exceeds specified length [%d]\n", digits_no);
        }
        if (status == -1)
        {
            printf("EOF detected. Terminating program.\n");
            return -1;
        }
    }   
}

void convert_binary(int input_no, int digits_no, char sign[], int output_no[], int *sum, bool *is_binary)
{
    int binary_multiplier = 1;
    if (input_no >= 0)
    {
        strcpy(sign, "[+]");
    }
    if (input_no < 0)
    {
        strcpy(sign, "[-]");
        input_no *= -1;
    }
    int remainder = input_no;
    for (int i = digits_no - 1; i >= 0; i--)
    {
        int output_digit = remainder % 10;
        output_no[i] = output_digit;
        *sum += output_digit * binary_multiplier;
        remainder = remainder / 10;
        
        if (output_digit != 0 && output_digit != 1)
        {
            *is_binary = false;
        }
        binary_multiplier *= 2;
    }
}

void print_results(char sign[], int digits_no, int output_no[], bool is_binary, int sum)
{
    printf("Final output: %s", sign);
    for (int i = 0; i < digits_no; i++)
    {
        printf("%6d", output_no[i]);
    }
    printf("\n");
    
    if (is_binary)
    {
        printf("The decimal equivalent is %s%d\n", strcmp(sign, "[+]") ? "-" : "", sum);
    }
}
// END OF HELPER FUNCTIONS