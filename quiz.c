/*Benjamin Bloomfield, bloomfib, October 2, 2024 
 *
 * This code works as a command-line quiz, that allows users to answer questions based on Linux,
 * GitHub, and C commands. Users can view or answer questions based on provided arguments, and
 * will receive feedback corresponding to their input.  
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Name of the function: main
 *
 * Parameters:
 *  int agrc --> the number of arguments the user inputs
 *  char *argv[] --> an array of command-line argument strings
 * Function Description:
 *  Processes command-lind arguments, and determines if the user wants to view or answer a question.
 *  Checks the input against varying cases, to provide feedback accordingly.
 * Return Value and Output:
 *  Returns --> EXIT_SUCCESS for correct input, and EXIT_FAILURE elsewise
 *  Output --> outputs varying messages corresponding to the users input, including quiz questions
 *  answer feedback, and help messages in case of bad input.
 */
int main(int argc, char *argv[]) {  

    // initializing variables for user's input, which will be used to determine questions and answers
    char *response = argv[1];
    char *userAnswer = argv[2];

    // initializing a list of possible answers and questions
    char *answers[] = {"ls", "EXIT_SUCCESS", "clone"};
    char *questions[] = {"In Linux, what command would you use to list the contents of the working directory?", 
                        "What statement would you return to indicate successful program termination in C?", 
                        "In GitHub, what command is used to clone a repository (git __)?"};

    // initializing different message outputs based on the users inputs
    char *helpMessage = "To view a quiz question, please enter: quiz -#, where # corresponds to a question number. \n"
                        "To answer a question, please enter: quiz -# \"ANSWER HERE\"";
    char *badUsage = "Please enter a valid input. \n"
                     "Enter \"quiz --help\" for more information.";
    

    // if the user provides no input, return EXIT_FAILURE to indicate that the program terminated with an error
    if (argc == 1)  { 
        puts(badUsage); // input a message to help the user understand what commands to use
        return EXIT_FAILURE;
    }


    // if the user inputs one value after 'quiz', check for the following conditionals
    else if (argc == 2) {

        // if the user enters '-#', output the corresponding question from the initialized array for entry #, and return EXIT_SUCCESS
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

        // checks to see if the user is attempting to answer question # based on the "-#" input
        if (strcmp(response, "-1") == 0) { 
            // check to see if the answer the user entered matches the correct answer in the 'answers' array for entry #
            if (strcmp(userAnswer, answers[0]) == 0) {
                puts("Great job, that is the correct answer!"); // if the answers match, output a message telling the user they are right
                return EXIT_SUCCESS;
            }

            // if the inputted answer, and correct answer don't match, output a message indicating it was false
            else {
                puts("That is wrong, so sorry!");
                return EXIT_SUCCESS;
            }
        }
        
        else if (strcmp(response, "-2") == 0) {
            if (strcmp(userAnswer, answers[1]) == 0) { 
                puts("Well done, that is correct!"); 
                return EXIT_SUCCESS;
            }

            else {
                puts("Sorry that is incorrect :(");
                return EXIT_SUCCESS;
            }
        }

        else if (strcmp(response, "-3") == 0) {
            if (strcmp(userAnswer, answers[2]) == 0) {
                puts("Awesome! That is correct!"); // if the answers match, output a message telling the user they are right
                return EXIT_SUCCESS;
            }

            else {
                puts("Sorry! That is wrong :(");
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