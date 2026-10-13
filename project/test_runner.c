#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool check_length(int input, int numlength);
int process_binary(int input_number, int digits_no, int output_array[], bool *is_binary);

void verify_digit_length_logic(void)
{
    printf("****Starting check_length() test****\n");
    assert(check_length(654321, 6) == true);  
    printf("Input number = 654321 || Length = 6 [TRUE] ---- PASSED\n");
    assert(check_length(0, 1) == true);     
    printf("Input number = 0 || Length = 1 ---- [TRUE] PASSED\n");  
    assert(check_length(101, 4) == false);      
    printf("Input number = 101 || Length = 4 ---- [FALSE] PASSED\n");   
    printf("PASSED ALL TESTS check_length()\n\n");
}

void verify_binary_conversion_logic(void)
{
    printf("****Starting binary math conversion assertions****\n");

    int mock_buffer[10] = {0};
    bool is_binary;
    int sum;
    
    sum = process_binary(110111, 6, mock_buffer, &is_binary);
    assert(is_binary == true);
    assert(sum == 55);
    assert(mock_buffer[0] == 1 && mock_buffer[1] == 1 && mock_buffer[2] == 0);
    printf("Input number = 110111 || Length = 6 ---- [BINARY: 55] PASSED\n"); 
    
    sum = process_binary(654321, 6, mock_buffer, &is_binary);
    assert(is_binary == false);
    assert(mock_buffer[0] == 6 && mock_buffer[1] == 5 && mock_buffer[2] == 4);
    printf("Input number = 654321 || Length = 6 ---- [BINARY: FALSE] PASSED\n"); 
    
    printf("PASSED ALL TEST convert binary math\n\n");
}

int main(void)
{
    printf("RUNNING TEST\n");
    verify_digit_length_logic();
    verify_binary_conversion_logic();
    printf("TESTS Ended.\n");
    return 0;
}