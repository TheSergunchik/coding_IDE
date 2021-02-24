/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 1, Part B
 * Contains mastermind class and the functions to run a game.
 * Implements code and response classes.
 */

#include "mastermind.h"

mastermind::mastermind(int n, int m) {
    //initializes each mastermind object and a code object for a guess.
    //Assigns the length of vector as well as the range of digits.
    codeLength = n;
    digitRange = m;
    code guess = code(codeLength, digitRange);

}

mastermind::mastermind()
// default constructor with values for = 5 and m= 10
{
    codeLength = 5;
    digitRange = 10;
    code guess = code(codeLength, digitRange);
}

void mastermind::printSecretCode() {
    // prints the secret code to the screen
    cout << endl << "SECRET CODE:  ";
    secretCode.printVector();
}

void mastermind::printGuessCode(code &guess) {
    // prints the most recent guessed code to the screen
    cout << "GUESS CODE:   ";
    guess.printVector();
}

code mastermind::humanGuess()
//Reads a guess from the keyboard and returns a code object that represents the guess
{
    code guess = code(codeLength, digitRange);
    guess.resetVector();
    guess.enterElements();
    return guess;
}

response mastermind::getResponse(const code &A)
//is passed one code (a guess code), and returns a response
{
    response guessResponse = response();
    guessResponse.setCorrectNumbers(secretCode.checkCorrect(A));
    guessResponse.setIncorrectNumbers(secretCode.checkIncorrect(A));
    return guessResponse;
}

bool mastermind::isSolved(const response &guessResponse, const response &correctResponse)
//passed a guess response and a correct response and returns true if the responses are equivalent
{
    return (guessResponse == correctResponse);
}

void mastermind::playGame()
{
    //program run to play a game

    //initializes the secret code and the guess variable
    secretCode = code(codeLength, digitRange);
    code guess = code(codeLength, digitRange);

    //creates two code class objects, the guess response and the correct response
    response guessResponse = response();
    response correctResponse = response(codeLength, 0);

    int attempts = 1;

    do{ //Starts the 10 attempts.
        cout << endl << "-- Attempt #" << attempts << " --" << endl << endl;

        //handles the inputted guess
        guess = humanGuess();
        guessResponse = getResponse(guess);

        // Prints both secret and guess code for grading purposes.
        printSecretCode();
        printGuessCode(guess);
        cout << "-------------------" << endl;

        //prints the response values for the inputted guess
        cout << guessResponse;

        attempts++;
    } while (((attempts <= 10) && (!(isSolved(guessResponse, correctResponse)))));
    //limits this loop to run for 10 attempts or until the code is guessed

    cout << endl << "-- GAME FINISHED --" << endl;

    // Provides two options: one where the game maker wins and one where the game breaker wins, depending if the
    // game breaker guessed the code in 10 attempts or less.
    if(isSolved(guessResponse, correctResponse))
    {
        cout << "The code breaker wins!" << endl << "The code was: ";
        secretCode.printVector();
    } else
    {
        cout << "The code maker wins!" << endl << "The code was: ";
        secretCode.printVector();
    }

}
