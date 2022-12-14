#include <stdio.h>
#include <cs50.h>
#include <math.h>

int cc_number_length(long cc_number);

int main(void)
{
    long cc_number;
    do
    {
        cc_number = get_long("Credit card number: ");
    } while (cc_number < 0); //card number must be an integer above 0

    int num1 = cc_number % 100 / 10;
    int num2 = cc_number % 10000 / 1000;
    int num3 = cc_number % 1000000 / 100000;
    int num4 = cc_number % 100000000 / 10000000;
    int num5 = cc_number % 10000000000 / 1000000000;
    int num6 = cc_number % 1000000000000 / 100000000000;
    int num7 = cc_number % 100000000000000 / 10000000000000;
    int num8 = cc_number % 10000000000000000 / 1000000000000000;

    num1 = num1*2;
    num2 = num2*2;
    num3 = num3*2;
    num4 = num4*2;
    num5 = num5*2;
    num6 = num6*2;
    num7 = num7*2;
    num8 = num8*2;

    int new_num1 = (num1 % 10)+(num1 % 100 / 10);
    int new_num2 = (num2 % 10)+(num2 % 100 / 10);
    int new_num3 = (num3 % 10)+(num3 % 100 / 10);
    int new_num4 = (num4 % 10)+(num4 % 100 / 10);
    int new_num5 = (num5 % 10)+(num5 % 100 / 10);
    int new_num6 = (num6 % 10)+(num6 % 100 / 10);
    int new_num7 = (num7 % 10)+(num7 % 100 / 10);
    int new_num8 = (num8 % 10)+(num8 % 100 / 10);

    int num9 = cc_number % 10;
    int num10 = cc_number % 1000 / 100;
    int num11 = cc_number % 100000 / 10000;
    int num12 = cc_number % 10000000 / 1000000;
    int num13 = cc_number % 1000000000 / 100000000;
    int num14 = cc_number % 100000000000 / 10000000000;
    int num15 = cc_number % 10000000000000 / 1000000000000;
    int num16 = cc_number % 1000000000000000 / 100000000000000;

    int sumA = new_num1 + new_num2 + new_num3 + new_num4 + new_num5 + new_num6 + new_num7 + new_num8;
    int sumB = num9 + num10 + num11 + num12 + num13 + num14 + num15 + num16;
    int sumC = sumA + sumB;

    printf("Checksum: %i \n", sumC);

    //if number does not pass checksum
    if ((sumC % 10) > 0)
    {
        printf("INVALID\n");
    }
    else
    {

    //get length of cc_number
    int length = cc_number_length(cc_number);

    //defining variable "first_two"
    int first_two = cc_number / (pow(10, length - 2));

    //identifying card types
    if (length == 15 && (first_two == 34 || first_two == 37))
    {
        printf ("AMEX \n");
    }

    else if (length == 16 && (first_two == 51 || first_two == 52 || first_two == 53 || first_two == 54 || first_two == 55))
    {
        printf ("MasterCard \n");
    }

    else if ((length == 16 || length == 13) && first_two / 10 == 4)
    {
        printf ("VISA \n");
    }
    //if card passes checksum but is still not a valid card number:
    else
    {
        printf("INVALID \n");
    }
    }
}

// function that accepts cc_number and returns the number of digits it has
int cc_number_length(long cc_number)
{
    int length = 1;
    while (cc_number >= 10)
    {
        cc_number = cc_number/10;
        length++;
    }
    return length;
}