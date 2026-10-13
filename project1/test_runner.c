#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool check_length(int input, int numlength);
int check_binary(int input_number, int digits_no, int output_array[], bool *is_binary);
int get_digits_no(int *digits_no);
int get_input_no(int *input_no, int digits_no);


void verify_digit_length_logic(void)
{
    printf("****Starting check_length() test****\n");
    assert(check_length(654321, 6) == true);  
    printf("Input number = 654321 || Length = 6 [TRUE] ---- PASSED\n");
    assert(check_length(0, 1) == true);     
    printf("Input number = 0 || Length = 1 ---- [TRUE] PASSED\n");  
    assert(check_length(101, 4) == true);      
    printf("Input number = 101 || Length = 4 ---- [TRUE] PASSED\n");   
    assert(check_length(0101, 4) == true);      
    printf("Input number = 0101 || Length = 4 ---- [TRUE] PASSED\n");   
    assert(check_length(10001, 4) == false);      
    printf("Input number = 10001 || Length = 4 ---- [FALSE] PASSED\n"); 
    printf("PASSED ALL TESTS check_length()\n\n");
}

void verify_binary_conversion_logic(void)
{
    printf("****Starting binary math conversion assertions****\n");

    int mock_buffer[10] = {0};
    bool is_binary;
    int sum;
    
    sum = check_binary(110111, 6, mock_buffer, &is_binary);
    assert(is_binary == true);
    assert(sum == 55);
    assert(mock_buffer[0] == 1 && mock_buffer[1] == 1 && mock_buffer[2] == 0);
    printf("Input number = 110111 || Length = 6 ---- [BINARY: 55] PASSED\n"); 
    
    sum = check_binary(654321, 6, mock_buffer, &is_binary);
    assert(is_binary == false);
    assert(mock_buffer[0] == 6 && mock_buffer[1] == 5 && mock_buffer[2] == 4);
    printf("Input number = 654321 || Length = 6 ---- [BINARY: FALSE] PASSED\n"); 
    
    printf("PASSED ALL TEST convert binary math\n\n");
}

void verify_user_input_loops(void)
{
    printf("****Starting user input loop tests (get_digits_no & get_input_number)****\n");
    
    int result_value = 0;
    int status;
    FILE *stream_check;
    FILE *mock_file = fopen("test_in.txt", "w");
    if (mock_file != NULL) 
    {
        fprintf(mock_file, "5\n");
        fclose(mock_file);

        // Redirect stream pointer to point at file instead of keyboard
        stream_check = freopen("test_in.txt", "r", stdin);
        assert(stream_check != NULL);
        status = get_digits_no(&result_value);

        assert(status == 1);            
        assert(result_value == 5);      
        printf("\nget_digits_no() Valid Input Test ---- PASSED\n");
    }

    mock_file = fopen("test_in.txt", "w");
    if (mock_file != NULL) 
    {
        // Empty file
        fclose(mock_file); 
        
        // Redirect stream pointer to point at empty file
        stream_check = freopen("test_in.txt", "r", stdin);
        assert(stream_check != NULL);
        status = get_input_no(&result_value, 3);
        assert(status == -1); 
        printf("get_input_no() EOF ---- PASSED\n");
    }

    printf("PASSED ALL USER INPUT HOOK TESTS\n\n");
}

int main(void)
{
    printf("RUNNING TEST\n");
    verify_digit_length_logic();
    verify_binary_conversion_logic();
    verify_user_input_loops();
    printf("TESTS Ended.\n");
    return 0;
}