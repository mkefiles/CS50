#include <stdio.h> // For Standard Input/Output
#include <ctype.h> // For isalpha()
#include <string.h> // For strlen()
#include <math.h> // For round()

// DESC: Provided desired value plus one for the null-terminator
#define MAX_NUMBER_OF_CHARACTERS 1001

const char sentence_punctuation[] = {'.', '!', '?'};

int main(void) {
    /*
    * SECTION - Declare/define empty variables
    */
    int num_of_letters = 0;
    int num_of_spaces = 0;
    int num_of_words = 0;
    int num_of_sentences = 0;

    /*
    * SECTION - Prompt the user for some text
    */
    char user_input[MAX_NUMBER_OF_CHARACTERS];
    printf("Text: ");
    if (fgets(user_input, MAX_NUMBER_OF_CHARACTERS, stdin) != NULL) {
        /*
        * SECTION - Count the number of letters, words and sentences in the text
        */
        // DESC: Loop through and assess string of characters
        int text_length = strlen(user_input);
        for (int i = 0; i < text_length; i++) {
            if (isalpha(user_input[i]) != 0) {
                num_of_letters++;
            }else if (user_input[i] == ' ') {
                num_of_spaces++;
            }else if (user_input[i] == '.' || user_input[i] == '?' || user_input[i] == '!') {
                // DESC: Assumes that a sentence ends with a form of punctuation
                num_of_sentences++;
            }
        }

        // DESC: Assumes that there is always one more word than number of spaces
        num_of_words = num_of_spaces + 1;

        /*
        * SECTION - Compute the Coleman-Liau index
        */
        float avg_num_of_letters = ((float)num_of_letters * 100.0) / (float) num_of_words;
        float avg_num_of_sentences = ((float)num_of_sentences * 100.0) / (float) num_of_words;
        float coleman_liau_index = (0.0588 * avg_num_of_letters) - (0.296 * avg_num_of_sentences) - 15.8;

        /*
        * SECTION - Print the grade level
        */
        if (coleman_liau_index < 1) {
            printf("Before Grade 1\n");
        } else if (coleman_liau_index >= 16) {
            printf("Grade 16+\n");
        } else {
            int rounded_grade = (int)round(coleman_liau_index);
            printf("Grade %i\n", rounded_grade);
        }
    } else {
        printf("Error reading input!");
    }
}