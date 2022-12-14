#include <stdio.h>
#include <cs50.h>
int main(void)
{
    //asks user for name (input) and gets a string
    string nameinput = get_string("what's your name?\n");
    //prints hello, name with the string input
    printf("hello, %s\n", nameinput);
}