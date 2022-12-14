// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

//----------------------------------------------------------------------------------------------------------------

// making new header

    uint8_t header[44];
    fread (&header, 44, 1, input);
    fwrite (&header, 44, 1, output);

//making new, volume-modified audio file

    int16_t temp; // **** Here: A declaration of a variable is where a program says that it needs a variable, without knowing what the value of the variable is
    while (fread (&temp, sizeof(int16_t), 1, input))
    {
        temp = temp * factor;
        fwrite (&temp, sizeof(int16_t), 1, output);
    }

//----------------------------------------------------------------------------------------------------------------

    // Close files
    fclose(input);
    fclose(output);
}
