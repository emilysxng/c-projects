#include <stdio.h>
#include <cs50.h>

void cc_number_length(int cc_number);

int main()
{
    int cc_number = 1234;
    cc_number_length(cc_number);
    printf("%d\n", cc_number);
}

void cc_number_length(int asdf)
{
    asdf = 5678;
    printf("%d\n", asdf);
}