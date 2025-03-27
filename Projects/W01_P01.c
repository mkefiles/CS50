/*
* There is a known bug that IF the user were to input a value...
* ... that exceeds the MAX_INPUT_LENGTH, the program will double-up...
* ... on the prompt-text because a new-line is being read as input
*/

/*
* This code handles the following edge-cases:
* - -1 (or other negative numbers)
* - 0 and 1
* - Any value exceeding 25
* - Entering of no input
*/

/*
* Notes:
* scanf() returns a 0 (false) or a 1 (true) if the input matches the formatter
* -- IF scanf() returns 0 (false), then it does NOT save the input to the variable
* -- An 'int' defaults to "1" as a value IF not assigned
*/

#include <stdio.h> // For Standard Input/Output
#include <stdlib.h> // For the atoi() function
#include <string.h> // For the strchr() function

// This value is the length plus one
#define MAX_INPUT_LENGTH 255

int main(void) {
    char user_input[MAX_INPUT_LENGTH];
    char *p;
    int height_value;

    // Output game introduction:
    printf("Welcome to BLOKZ!!\n");
    printf("INSTRUCTIONS: Provide a numerical number between 2 and 25.\n");
    
    // Loop until correct input received
    do {
        printf("Enter height input: ");
        fgets(user_input, sizeof(user_input), stdin);
        
        // Check if 'user_input' has a '\n' char in it
        if ((p = strchr(user_input, '\n')) != NULL) {
            // If so, swap it out with end-of-line
            *p = '\0';
        }

        // Convert string to integer
        height_value = atoi(user_input);
    } while(height_value < 2 || height_value > 25);


    // int height_value = 8;
    int incrementer = 1;
    for (int i = height_value; i > 0; i--) {
        for (int j = height_value - incrementer; j > 0; j--) {
            printf(" ");
        }
        for (int k = 0; k < incrementer; k++) {
            printf("#");
        }
        printf("  ");

        for (int k = 0; k < incrementer; k++) {
            printf("#");
        }

        for (int j = height_value - incrementer; j > 0; j--) {
            printf(" ");
        }

        printf("\n");
        incrementer++;
    }
}