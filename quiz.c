/*Benjamin Bloomfield, October 3, 2024 
 *
 * WHAT THIS DO

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DESCRIBE FUNCTION
int main(int argc, char *argv[]) {  

    // initializing variables for user input, which will be used to determine questions and answers
    char *response = argv[1];
    char *userAnswer = argv[2];

    // initializing a list of possible answers and questions
    char *answers[] = {"ls", "EXIT_SUCCESS", "clone"};
    char *questions[] = {"In Linux, what command would you use to list the contents of the working directory?", 
                        "What statement would you return to  indicate successful program termination in C?", 
                        "In GitHub, what command is used to clone a repository (git __)?"};

    // initializing different message outputs based on the users inputs
    char *helpMessage = "To view a quiz question, please enter: quiz -#. \n"
                        "To answer a question, please enter: quiz -# \"my answer\" ";
    char *badUsage = "Please enter a valid input. \n"
                     "Enter \"quiz --help\" for more information.";
    

    // if the user provides no input, return EXIT_FAILURE to indicate that the program terminated with an error
    if (argc == 1)  { 
        puts(badUsage); // input a message to help the user understand what commands to use
        return EXIT_FAILURE;
    }


    // if the user inputs one value after 'quiz', check for the following conditionals
    else if (argc == 2) {
        // if the user enters '-#', output the corresponding question from the initialized array, and return EXIT_SUCCESS
        if (strcmp(response, "-1") == 0) {
            puts(questions[0]);
            return EXIT_SUCCESS;
        }

        else if (strcmp(response, "-2") == 0) {
            puts(questions[1]);
            return EXIT_SUCCESS;
        }

        else if (strcmp(response, "-3") == 0) {
            puts(questions[2]);
            return EXIT_SUCCESS;
        }

        // if the user enters '--help', then output the help message, to indicate what commands to enter to access a question or answer
        else if (strcmp(response, "--help") == 0) {
            puts(helpMessage);
            return EXIT_SUCCESS;
        }

        // if the user does not enter a proper option, output a message, and indicate the program terminated with an error
        else {
            puts(badUsage);
            return EXIT_FAILURE;
        }
    }


    // if the user inputs two values after 'quiz', check the following conditionals, for an answer to the question
    else if (argc == 3) {
        // checks to see if the user is attempting to answer question 1
        if (strcmp(response, "-1") == 0) { 
            // check to see if the answer the user entered matches the correct answer in the 'answers' array
            if (strcmp(userAnswer, answers[0]) == 0) {
                puts("Great job, that is the correct answer!"); // if the answers match, output a message telling the user they are right
                return EXIT_SUCCESS;
            }

            // if the inputted answer, and correct answer don't match, output a message indicating it was false
            else {
                printf("Incorrect. The correct answer is \"%s\".\n", answers[0]);
                return EXIT_SUCCESS;
            }
        }
        
        // checks to see if the user is attempting to answer question 2
        else if (strcmp(response, "-2") == 0) {
            // check to see if the answer the user entered matches the correct answer in the 'answers' array
            if (strcmp(userAnswer, answers[1]) == 0) { 
                puts("Well done, that is correct!"); // if the answers match, output a message telling the user they are right
                return EXIT_SUCCESS;
            }

            // if the inputted answer, and correct answer don't match, output a message indicating it was false
            else {
                printf("Incorrect. The correct answer is \"%s\".\n", answers[1]);
                return EXIT_SUCCESS;
            }
        }

        // checks to see if the user is attempting to answer question 3
        else if (strcmp(response, "-3") == 0) {
            // check to see if the answer the user entered matches the correct answer in the 'answers' array
            if (strcmp(userAnswer, answers[2]) == 0) {
                puts("Awesome! That is correct!"); // if the answers match, output a message telling the user they are right
                return EXIT_SUCCESS;
            }

            // if the inputted answer, and correct answer don't match, output a message indicating it was false
            else {
                printf("Incorrect. The correct answer is \"%s\".\n", answers[2]);
                return EXIT_SUCCESS;
            }
        }
        
        else {
            puts(badUsage);
            return EXIT_FAILURE;
        }
    }
    

    // if the user input does not match any of the proper conditionals, output a message to tell them how to
    else {
        puts(badUsage);
        return EXIT_FAILURE;
    }

}
