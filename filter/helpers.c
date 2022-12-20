#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int n = 0; n < height; n++)
    {
        for (int x = 0; x < width; x++)
        {
            int average_RGB = round((image[n][x].rgbtRed + image[n][x].rgbtGreen + image[n][x].rgbtBlue) / 3.0 );
            image[n][x].rgbtRed = average_RGB;
            image[n][x].rgbtBlue = average_RGB;
            image[n][x].rgbtGreen = average_RGB;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int n = 0; n < height; n++)
    {
        for (int x = 0; x < width; x++)
        {
            int tempRed = round(.393 * image[n][x].rgbtRed + .769 * image[n][x].rgbtGreen + .189 * image[n][x].rgbtBlue);
            int tempGreen = round(.349 * image[n][x].rgbtRed + .686 * image[n][x].rgbtGreen + .168 * image[n][x].rgbtBlue);
            int tempBlue = round(.272 * image[n][x].rgbtRed + .534 * image[n][x].rgbtGreen + .131 * image[n][x].rgbtBlue);

            if (tempRed > 255)
            {
                tempRed = 255;
            }
            if (tempGreen > 255)
            {
                tempGreen = 255;
            }
            if (tempBlue > 255)
            {
                tempBlue = 255;
            }

            image[n][x].rgbtRed = tempRed;
            image[n][x].rgbtGreen = tempGreen;
            image[n][x].rgbtBlue = tempBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int n = 0; n < height; n++)
    {
        for (int x = 0; x < width / 2 ; x++)
        {
            int tempRed = image[n][x].rgbtRed;
            int tempGreen = image[n][x].rgbtGreen;
            int tempBlue = image[n][x].rgbtBlue;

            image[n][x].rgbtRed = image[n][width - x - 1].rgbtRed;
            image[n][x].rgbtGreen = image[n][width - x - 1].rgbtGreen;
            image[n][x].rgbtBlue = image[n][width - x - 1].rgbtBlue;

            image[n][width - x - 1].rgbtRed = tempRed;
            image[n][width - x - 1].rgbtGreen = tempGreen;
            image[n][width - x - 1].rgbtBlue = tempBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];                      // make copy of image
    for (int n = 0; n < height; n++)
    {
        for (int x = 0; x < width; x++)
        {
            copy[n][x].rgbtRed = image[n][x].rgbtRed;
            copy[n][x].rgbtGreen = image[n][x].rgbtGreen;
            copy[n][x].rgbtBlue = image[n][x].rgbtBlue;

        }
    }

    for (int current_height = 0; current_height < height; current_height++)
    {
        for (int current_width = 0; current_width < width; current_width++)
        {
            int counter = 0;
            float temp_red = 0;
            float temp_green = 0;
            float temp_blue = 0;

            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    int current_grid_height = current_height + i;
                    int current_grid_width = current_width + j;

                    if ((current_grid_height >= 0 && current_grid_height < height) && (current_grid_width >= 0 && current_grid_width < width))
                    {
                        counter++;
                        temp_red += copy[current_grid_height][current_grid_width].rgbtRed;
                        temp_green += copy[current_grid_height][current_grid_width].rgbtGreen;
                        temp_blue += copy[current_grid_height][current_grid_width].rgbtBlue;
                    }
                }
            }
            image[current_height][current_width].rgbtRed = round(temp_red / counter);
            image[current_height][current_width].rgbtGreen = round(temp_green / counter);
            image[current_height][current_width].rgbtBlue = round(temp_blue / counter);
        }
    }
    return;
}


//run: ./filter [-g, -s, -r, or -b] images/[input.bmp] [output.bmp]