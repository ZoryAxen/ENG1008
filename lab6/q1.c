#include <stdio.h>

int intergerpower(int base, int exponent);

int main(void)
{
    int base;
    int exponent;
    int answer;

    puts("Enter base: ");
    scanf("%d", &base);
    puts("Enter exponent: ");
    scanf("%d", &exponent);
    answer = intergerpower(base, exponent);
    printf("%d", answer);
}

int intergerpower(int base, int exponent)
{
    int answer = 1;
    if (exponent == 0)
    {
        return answer;
    }
    else
    {
        for (int i = 0; i < exponent; i++)
        {
            answer *= base;
        }
        return answer;
    }
}