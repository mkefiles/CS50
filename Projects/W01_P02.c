/*
* NOTES:
* - The input MUST be a string because the integer representation of a credit...
* ... card number is too long for what an integer can hold
* - It MUST check for string-literal zeroes because atoi() returns a '0' if...
* ... the value is '0' OR if it is a char, which can throw false negatives
*/

#include <stdio.h> // For Standard Input/Output
#include <stdlib.h> // For the atoi() function
#include <string.h> // For the strchr() and strlen() functions

// This value is the length plus one
#define MAX_INPUT_LENGTH 255

#define AMEX_START_01 "34"
#define AMEX_START_02 "37"

#define MC_START_01 "51"
#define MC_START_02 "52"
#define MC_START_03 "53"
#define MC_START_04 "54"
#define MC_START_05 "55"

#define VISA_START_01 "4"

#define VISA_LENGTH 13
#define AMEX_LENGTH 15
#define MC_OR_VISA_LENGTH 16

void isValidNumber(char *str);

int main(void) {
    /* STEP ONE: INTRO. AND INSTRUCTIONS */
    printf("Welcome to the Credit Card Validator!!\n");
    printf("INSTRUCTIONS: At the prompt, please provide a CC number.\n");
    printf("NOTES ON LENGTH: Visa -> 13 || 16, AmEx -> 15 and MC -> 16\n");

    /* STEP TWO: GET USER INPUT AND CONFIRM IT IS NUMERICAL */
    // Loop until user-input is entirely numerical
    int skip_flag = 0;
    char user_input[MAX_INPUT_LENGTH];
    char *p;
    do {
        // Counter used to confirm all characters are numerical
        int counter = 0;

        printf("Card Number: ");
        scanf(" %s", user_input);

        // Loop through each individual character in the string
        for (int i = 0; i < strlen(user_input); i++) {
            // First check if it is a string-literal zero
            if (user_input[i] == '0') {
                counter = counter + 1;
                continue;
            }
            // Then check if it is a non-numerical character
            else if (atoi(&user_input[i]) == 0) {
                printf("Letter found... try again\n");
                break;
            }
            // If not '0' and not non-numerical, then it must be numerical
            else {
                counter = counter + 1;
                continue;
            }
        }

        // If counter equals strlen(), then all characters were numerical
        if (counter == strlen(user_input)) {
            // End the loop
            skip_flag = 1;
        }
    } while (skip_flag == 0); // Keep looping while 'skip' is false

    /* STEP THREE: CHECK IF LENGTH REQUIREMENT MET */
    /* STEP FOUR: IF MET, CHECK IF CARD NUMBER SATISFIES ALGORITHM */
    switch (strlen(user_input)) {
        case VISA_LENGTH:
            isValidNumber(user_input);
            break;
        case AMEX_LENGTH:
            isValidNumber(user_input);
            break;
        case MC_OR_VISA_LENGTH:
            isValidNumber(user_input);
            break;
        default:
            printf("\nINVALID\n");
            break;
    }

    // Terminate the program
    return 0;
}

void isValidNumber(char *card_number) {
    // Check the length
    int card_num_length = strlen(card_number);

    // Declare/define necessary default values
    int skip_flag = 0;
    int sum_of_values = 0;
    char value_at_card_num_index;
    char str_of_evens[20];

    // Loop through card number starting at end
    for (int i = card_num_length - 1; i >= 0; i--) {
        char sum_to_str[10];
        switch (skip_flag) {
            case 0:
                // Add 'odd' values together
                value_at_card_num_index = card_number[i];
                sum_of_values = sum_of_values + atoi(&value_at_card_num_index);

                // Toggle flag
                skip_flag = 1;
                break;
            case 1:
                // Add 'even' values together (with multiplier)
                value_at_card_num_index = card_number[i];

                // Convert each str to int, multiply by two, convert back to str in new variable
                sprintf(sum_to_str, "%d", (atoi(&value_at_card_num_index) *2));

                // Concatenate each substring to a new string
                strcat(str_of_evens, sum_to_str);
                 
                // Toggle flag
                skip_flag = 0;
                break;
        }
    }

    // Loop through and add 'even' product-digits together
    char value_at_sum_index;
    for (int i = 0; i < strlen(str_of_evens); i++) {
        value_at_sum_index = str_of_evens[i];
        sum_of_values = sum_of_values + atoi(&value_at_sum_index);
    }

    // Check if total sum is evenly divisible by 10
    if (sum_of_values % 10 == 0) {

        // If divisible by 10, determine card type by prefix
        if (strncmp(card_number, AMEX_START_01, 2) == 0) {
            printf("\nAMEX\n");
        }
        else if (strncmp(card_number, AMEX_START_02, 2) == 0) {
            printf("\nAMEX\n");
        }
        else if (strncmp(card_number, MC_START_01, 2) == 0) {
            printf("\nMASTERCARD\n");
        }
        else if (strncmp(card_number, MC_START_02, 2) == 0) {
            printf("\nMASTERCARD\n");
        }
        else if (strncmp(card_number, MC_START_03, 2) == 0) {
            printf("\nMASTERCARD\n");
        }
        else if (strncmp(card_number, MC_START_04, 2) == 0) {
            printf("\nMASTERCARD\n");
        }
        else if (strncmp(card_number, MC_START_05, 2) == 0) {
            printf("\nMASTERCARD\n");
        }
        else if (strncmp(card_number, VISA_START_01, 1) == 0) {
            printf("\nVISA\n");
        }
        else {
            printf("\nCARD-TYPE UNKNOWN - NUMBER VALID\n");
        }
    } else {
        printf("\nINVALID\n");
    }
}