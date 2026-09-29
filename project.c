#include <stdio.h>
#include <math.h>

// 1. Prompt user input to enter number of digits (n)
// 2. Prompt user to enter the n-digit number
// 3. Verify input
// 4. Produce individual digits and display them
// 5. Check for evidence of binary numbers
// 6. Convert them to decimal format if true and display them

int main(void)
{
    int  sum = 0, digits_no, input_number;
    bool is_binary = 1;
    
    printf("Enter number of digits: ");
    scanf("%d", &digits_no);
    printf("Enter n-digit number: ");
    scanf("%d", &input_number);

    // VERIFICATION TO BE IMPLEMENTED

    printf("Final Output: ");
    for (int i = 1, remainder = input_number, output_digit = 0; i <= digits_no; i++) 
    {
        output_digit = remainder / (int)pow(10, digits_no - i);
        remainder = remainder % (int)pow(10, digits_no - i);
        printf("%d ",  output_digit);
        if (output_digit != 0 && output_digit != 1)
        {
            is_binary = 0;
        }
    }
    if (is_binary) 
    {
        for (int j = 1, remainder = input_number; j <= digits_no; j++)
        
        {
            // Increment sum by 2 to the power of digits no - 1 * number divided by 10 to the power of digits no -1
            // Retrieve the remaining numbers for the next loop
            // Repeat loop until digits no - 1 == 0 (2^0)
            sum += (remainder / (int)pow(10, digits_no - j)) * (int)pow(2, digits_no - j);
            remainder = remainder % (int)pow(10, digits_no - j);
        }
        printf("\nThe decimal equivalent is %d", sum);
    }
}