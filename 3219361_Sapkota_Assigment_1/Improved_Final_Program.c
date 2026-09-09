/*
 * EECS 348 Assignment 1
 * Program: Number Guessing Game
 *
 * Description:
 * This program uses a fixed secret number between 1 and 10.
 * The user gets up to 3 tries to guess the number.
 *
 * Input:
 * User enters an integer guess.
 *
 * Output:
 * The program tells the user if the guess is too high,
 * too low, or correct. It also prints a final win or lose message.
 *
 * Collaborators: None
 * Other Sources: GitHub Copilot and Google Gemini
 * Author: Prabesh Sapkota
 * Creation Date: September 8, 2026
 * Revision Date: September 8, 2026
 * Revisions: Added input validation, constants, and comments.
 */

#include <stdio.h>

int main(void) {
    // Store the fixed secret number and maximum number of attempts.
    const int secret = 7;
    const int max_attempts = 3;

    // Store the user's guess.
    int guess;

    // Keep track of whether the user guessed the number correctly.
    int won = 0;

    // Display the instructions for the game.
    printf("Guess a number between 1 and 10.\n");

    // Give the user up to three attempts to guess the secret number.
    for (int attempt = 1; attempt <= max_attempts; attempt++) {

        // Ask the user to enter a guess.
        printf("Attempt %d/%d. Enter your guess: ",
               attempt, max_attempts);

        // Read the user's guess and check that an integer was entered.
        if (scanf("%d", &guess) != 1) {
            // Display an error message if the input is not an integer.
            printf("Invalid input. Please enter an integer.\n");

            // End the program because the input was invalid.
            return 1;
        }

        // Check if the user's guess is correct.
        if (guess == secret) {
            // Tell the user that they won.
            printf("Correct! You win!\n");

            // Record that the user won.
            won = 1;

            // Stop the loop immediately after a correct guess.
            break;
        }
        // Check if the user's guess is lower than the secret number.
        else if (guess < secret) {
            // Tell the user the guess was too low.
            printf("Too low!");

            // Tell the user to try again if attempts remain.
            if (attempt < max_attempts) {
                printf(" Try again.");
            }

            // Move to the next line.
            printf("\n");
        }
        // If the guess is not correct or low, it must be too high.
        else {
            // Tell the user the guess was too high.
            printf("Too high!");

            // Tell the user to try again if attempts remain.
            if (attempt < max_attempts) {
                printf(" Try again.");
            }

            // Move to the next line.
            printf("\n");
        }
    }

    // If the user did not guess correctly, display the losing message.
    if (!won) {
        printf("Sorry, you lose! The correct number was %d.\n", secret);
    }

    // Return 0 to indicate that the program finished successfully.
    return 0;
}
