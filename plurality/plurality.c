#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int x = 0; x < candidate_count; x++)
    {
        if (strcmp(name, candidates[x].name) == 0)
        {
            candidates[x].votes++; //this value will carry over outside of this function because arrays are pass by reference.
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int most_votes = 0;
    for (int n = 0; n < candidate_count; n++)
    {
        if (candidates[n].votes > most_votes)
        {
            most_votes = candidates[n].votes;
        }
    }

    for (int j = 0; j < candidate_count; j++)
    {
        if (most_votes == candidates[j].votes)
        {
            printf("%s \n", candidates[j].name); //probably dont need to make a new for loop - just add this if ststament to the end of the for loop above
        }
    }
    return;
}