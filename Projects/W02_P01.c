/*
* Author: Mike Files
* Name: Scrabble (Mini)
* Notes:
* - The word must be between 2 and 15 characters long (per scrabble rules)
* - This only allows one guess for each player and only has two players
* - CS50 version allows for punctuation, however mine does not (to follow true scrabble rules)
* - The ALLOWABLE_STRING_LENGTH of 50 is an arbitrary value, however it is...
* ... important to ensure that the scanf() value is one less to avoid buffer...
* ... overflows because we must allow for the input AND one slot for the null-terminator
*/

#include <stdio.h> // For Standard Input/Output
#include <string.h> // For strlen()
#include <ctype.h> // For isdigit()

#define ALLOWABLE_STRING_LENGTH 50
#define MAX_WORD_LENGTH 15
#define MIN_WORD_LENGTH 2

const char alphabet_letters_upper[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
    'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
    'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};
const char alphabet_letters_lower[] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
    'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
    's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};
const int alphabet_rating[] = {
    1, 3, 3, 2, 1, 4, 2, 4, 1,
    8, 5, 1, 3, 1, 1, 3, 10, 1,
    1, 1, 1, 4, 4, 8, 4, 10
};

int grade_player_input (char p_name[]);

int main (void) {
    // DESC: Game introduction
    printf("Welcome to Scrabble (Mini)\n");

    // DESC: Get the input, validate it then score it
    int player_one_word_score = grade_player_input("Player 1");
    int player_two_word_score = grade_player_input("Player 2");
    
    // DESC: Determine who the winner is
    if (player_one_word_score == player_two_word_score) {
        printf("Tie!\n");
    } else if (player_one_word_score > player_two_word_score) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }

    // DESC: Exit the program
    return 0;
}

int grade_player_input (char p_name[]) {

    char player_input[ALLOWABLE_STRING_LENGTH];
    int input_length = 0;

    // DESC: Continue requesting input until it meets criteria
    int kill_flag = 0;
    do {
        printf("%s: ", p_name);
        scanf("%49s", player_input);
        input_length = strlen(player_input);
        int non_alphabetical_counter = 0;

        // DESC: Verify that word-length is between 2 and 15 characters
        if (input_length < MIN_WORD_LENGTH || input_length > MAX_WORD_LENGTH) {
            printf("Word-length must be between 2 and 15 characters.\n");
            printf("Your word is %i characters long. Please try again!\n", input_length);
            kill_flag = 0;
            continue;
        }
        
        // DESC: Verify that string provided only contains A-Za-z
        else {
            for (int i = 0; i < input_length; i++) {
                // DESC: Loop through each character and check if it is a digit
                if (isdigit(player_input[i])) {
                    // DESC: If digit is found, increment counter
                    non_alphabetical_counter++;
                }
            }
            // DESC: If value is greater-than zero, then there are digits in input
            if (non_alphabetical_counter > 0) {
                printf("Word cannot contain any numerical values.\n");
                printf("Please try again!\n");
                kill_flag = 0;
            } else {
                // DESC: Input is acceptable; Leave loop
                kill_flag = 1;
            }
        }
    } while (kill_flag != 1);

    // DESC: Score the user-input
    int word_score = 0;
    int alphabet_length = 26;
    for (int i = 0; i < input_length; i++) {
        for (int j = 0; j < alphabet_length; j++) {
            if (player_input[i] == alphabet_letters_upper[j] || player_input[i] == alphabet_letters_lower[j]) {
                word_score = word_score + alphabet_rating[j];
            }
        }
    }

    // DESC: Return the calculated score of the word
    return word_score;
}
