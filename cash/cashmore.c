#include <stdio.h>
#include <cs50.h>

// only gives change in coins (no bills)
//also only USD

int main(void)
{
    float dollars;
    do
    {
        dollars = get_float("How many dollars? \n");
    } while (dollars < 0);

    if (dollars == 0)
    {
        printf("You have no money...\n");
    }
    else
    {
        int cents = dollars * 100;
        printf("Total Cents: %i \n", cents);

        int quarters = 0;
        while (cents >= 25)
        {
            quarters++;
            cents = cents - 25;
        }
        printf("Quarters: %i \n", quarters);

        int dimes = 0;
        while (cents >= 10)
        {
            dimes++;
            cents = cents - 10;
        }
        printf("Dimes: %i \n", dimes);

        int nickels = 0;
        while (cents >= 5)
        {
            nickels++;
            cents = cents - 5;
        }
        printf("Nickels: %i \n", nickels);

        int pennies = 0;
        while (cents >= 1)
        {
            pennies++;
            cents = cents - 1;
        }
        printf("Pennies: %i \n", pennies);

        int coins = quarters + dimes + nickels + pennies;
        printf("Total Coins: %i \n", coins);
    }
}