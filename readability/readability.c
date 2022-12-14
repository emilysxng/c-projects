#include <stdio.h>
#include <math.h>
#include <cs50.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Input text here: \n");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    printf("Letters: %i \n", letters);
    printf("Words: %i \n", words);
    printf("Sentences: %i \n", sentences);

    int avg_letters = (letters / words) * 100;
    int avg_sentences = (sentences / words) * 100;

    float grade_level = 0.0588 * avg_letters - 0.296 * avg_sentences - 15.8;
    int int_grade_level = round(grade_level); 

    if (int_grade_level < 1)
    {
        printf("Grade Level: Below grade 1 \n");
    }

    else if (int_grade_level > 1 && int_grade_level < 12)
    {
        printf("Grade Level: %i \n", int_grade_level);
    }

    else if (int_grade_level == 13)
    {
        printf("Grade Level: First year university \n");
    }

    else if (int_grade_level == 14)
    {
        printf("Grade Level: Second year university \n");
    }

    else if (int_grade_level == 15)
    {
        printf("Grade Level: Third year university \n");
    }

    else
    {
        printf("Grade Level: Fourth year university+ \n");
    }
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if ((text[i] >= 48 && text[i] <= 57) || (text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 1;
    for (int x = 0; text[x] != '\0'; x++)
    {
        if (text[x] == 32)
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int y = 0; text[y] != '\0'; y++)
        if (text[y] == 33 || text[y] == 46 || text[y] == 63)
        {
            sentences++;
        }
    return sentences;
}