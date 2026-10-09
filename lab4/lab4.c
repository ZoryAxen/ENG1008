#include <stdio.h>
#include <math.h>

int main(void) 
{
    float principal, interest, compound_interest;
    int years = 10;

    printf("Ener your principal amount and interest rate to see your copmpound interest for 10 years. Restriction applies.\n");
    printf("Enter 0 for both principal and interest rate to exit the program.\n");

    // Get user input for principal and interest rate
    // Verify user input
    // Loop until valid input or terminate program
    while (1) {
        printf("Enter principal amount ($):");
        scanf("%f", &principal);
        printf("Enter interest rate (%%): ");
        scanf("%f", &interest);

        if (principal == 0 && interest == 0) 
        {
            printf("Terminating program.\n");
            break;
        } 
        else if (principal <= 1000 || principal >= 50000) 
        {
            printf("Invalid input. Valid inputs for principal amount is between $1000 and $50000\n");
            continue;
        } 
        else if (principal <= 20000 && (interest <= 0.5 || interest >= 2.49))
        {
            printf("Invalid input. Valid inputs for interest rate is between 0.5%% and 2.49%% for principal amount lesser than or equal to $20000\n");
            continue;
        }
        else if (principal >  20000 && (interest <= 2.5 || interest >= 5.0))
        {
            printf("For principal amount greater than $20000, valid values for interest rate is betweeen 2.5%% and 5%%.\n");
            continue;
        }

        for (int i = 1; i <= years; i++)
        {
            // Calculate compound interest
            compound_interest = principal * pow((1 + interest/100), i);
            // Display each's year interest
            printf("Year %d: %.2f \n", i, compound_interest);
        }
        printf("After %d years, your investment will be worth: $%.2f\n", years, compound_interest);
    }
}