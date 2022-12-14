#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2) // only one cmd line argument
    {
        printf("Usage: ./recover IMAGE \n");
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r"); // open the forensic image
    if (input_file == NULL) //check if it can be opened (if it has a valid address)
    {
        printf("There was an error opening the file: Please try again. \n");
        return 2;
    }

    //store unsigned blocks of 512 bytes into an array (declare variable)
    unsigned char buffer[512];

    // counter for images found
    int count_image = 0;

    // file pointer for recovered images
    FILE *output_file = NULL; //FILE is a data type

    //char filename[8]
    char *filename = malloc(8 * sizeof(char));

    //read the blocks of 512 bytes
    while(fread(buffer, sizeof(char), 512, input_file)) //fread returns number of items of size "size" read - while loop will stop until it stops reading
    {
        //check if first 4 bytes indicate start of header
        if (buffer[0] == 0xff && buffer[1] == 0xdf && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (count_image > 0)
            {
                fclose(output_file);
            }

            //create filenames
            sprintf (filename, "%03i.jpg", count_image);

            //open output file to write the input file into
            output_file = fopen(filename, "w");

            //update counter
            count_image++;
        }
        //check if filename has been created, so you can write image data onto it.
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }

    }
    free(filename);
    fclose(input_file);

    return 0;
}