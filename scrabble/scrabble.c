#include <stdio.h>
#include <cs50.h>
#include <string.h>

int compute_score(string uppercase_input_word);
string make_word_uppercase(string input_word);

int test_compute_score(void); //test to see if compute_score function works

int main(void)
{
    if (test_compute_score() == 1)
    {
        printf("test_compute_score failed!\n");
        return 1;
    }

    string player_1_word = get_string("Player 1 word: "); // ask both players for their word
    string player_2_word = get_string("Player 2 word: ");

    string uppercase_player_1_word = make_word_uppercase(player_1_word); //both words made uppercase
    string uppercase_player_2_word = make_word_uppercase(player_2_word);

    int player_1_score = compute_score(uppercase_player_1_word); //computes score of each word
    int player_2_score = compute_score(uppercase_player_2_word);

    printf("Player 1 score: %i \n", player_1_score); //prints both player's score
    printf("Player 2 score: %i \n", player_2_score);

    if (player_1_score > player_2_score) //determines a winner or a tie
    {
        printf("Player 1 wins! \n");
    }
    else if (player_2_score > player_1_score)
    {
        printf("Player 2 wins! \n");
    }
    else
    {
        printf("Tie! \n");
    }
}

int compute_score(string uppercase_input_word) //function that computes score
{
    int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int player_score = 0;
    for (int n = 0; uppercase_input_word[n] != '\0'; n++)
    {
        player_score = player_score + POINTS[ (uppercase_input_word[n] - 65) ];
    }
    return player_score;
}

int test_compute_score() //test to see if compute_score function works
{
    if (compute_score("QUIZZED") != 35) {
        return 1;
    }

    if (compute_score("APPLE") != 9) {
        return 1;
    }

    return 0;
}

string make_word_uppercase(string input_word) //function that makes word uppercase
{
    for(int i = 0; input_word[i] != '\0'; i++)
    {
        if (input_word[i] >= 97 && input_word[i] <= 122)
        {
        input_word[i] = input_word[i] - 32;
        }
    }
    return input_word;
}