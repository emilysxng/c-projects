    int player_1_score = 0;
    for (int x = 0; uppercase_player_1_word[x] != 0; x++)
    {
        if (uppercase_player_1_word[x] == 65 || uppercase_player_1_word[x] == 69 || uppercase_player_1_word[x] == 73 || uppercase_player_1_word[x] == 76 || uppercase_player_1_word[x] == 78 || uppercase_player_1_word[x] == 79 || (uppercase_player_1_word[x] >= 82 && uppercase_player_1_word[x] <= 85))
        {
            player_1_score = player_1_score + 1;
        }
        else if (uppercase_player_1_word[x] == 68 || uppercase_player_1_word[x] == 71)
        {
            player_1_score = player_1_score + 2;
        }
        else if (uppercase_player_1_word[x] == 66 || uppercase_player_1_word[x] == 67 || uppercase_player_1_word[x] == 77 || uppercase_player_1_word[x] == 80)
        {
            player_1_score = player_1_score + 3;
        }
        else if (uppercase_player_1_word[x] == 70 || uppercase_player_1_word[x] == 72 || uppercase_player_1_word[x] == 86 || uppercase_player_1_word[x] == 87 || uppercase_player_1_word[x] == 89)
        {
            player_1_score = player_1_score + 4;
        }
        else if (uppercase_player_1_word[x] == 75)
        {
            player_1_score = player_1_score + 5;
        }
        else if (uppercase_player_1_word[x] == 74 || uppercase_player_1_word[x] == 88)
        {
            player_1_score = player_1_score + 8;
        }
        else if (uppercase_player_1_word[x] == 81 || uppercase_player_1_word[x] == 90)
        {
            player_1_score = player_1_score + 10;
        }
    }

    int player_2_score = 0;
    for (int x = 0; uppercase_player_2_word[x] != 0; x++)
    {
        if (uppercase_player_2_word[x] == 65 || uppercase_player_2_word[x] == 69 || uppercase_player_2_word[x] == 73 || uppercase_player_2_word[x] == 76 || uppercase_player_2_word[x] == 78 || uppercase_player_2_word[x] == 79 || (uppercase_player_2_word[x] >= 82 && uppercase_player_2_word[x] <= 85))
        {
           player_2_score = player_2_score + 1;
        }
        else if (uppercase_player_2_word[x] == 68 || uppercase_player_2_word[x] == 71)
        {
            player_2_score = player_2_score + 2;
        }
        else if (uppercase_player_2_word[x] == 66 || uppercase_player_2_word[x] == 67 || uppercase_player_2_word[x] == 77 || uppercase_player_2_word[x] == 80)
        {
            player_2_score = player_2_score + 3;
        }
        else if (uppercase_player_2_word[x] == 70 || uppercase_player_2_word[x] == 72 || uppercase_player_2_word[x] == 86 || uppercase_player_2_word[x] == 87 || uppercase_player_2_word[x] == 89)
        {
            player_2_score = player_2_score + 4;
        }
        else if (uppercase_player_2_word[x] == 75)
        {
            player_2_score = player_2_score + 5;
        }
        else if (uppercase_player_2_word[x] == 74 || uppercase_player_2_word[x] == 88)
        {
            player_2_score = player_2_score + 8;
        }
        else if (uppercase_player_2_word[x] == 81 || uppercase_player_2_word[x] == 90)
        {
            player_2_score = player_2_score + 10;
        }
    }