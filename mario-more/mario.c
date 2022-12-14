#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //user input for height
    int height;

    do
    {
        height = get_int("Height: \n");
    } while (height > 8 || height < 1);

    //height of pyramid
    for (int y=0; y<height; y++)
    {
        //width of pyramid
        for (int x=0; x<height; x++)
        {
            if (x+y < height-1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }

        //double space
        printf("  ");

        //the other side
        for (int x=0; y>=x; x++)
        {
            printf("#");
        }

        printf("\n");
    }
}