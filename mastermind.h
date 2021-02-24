/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 1, Part B
 * Contains code class and all necessary functions (checkCorrect, checkIncorrect).
 * Implements code class to run a game of Mastermind.
 */

#include <iostream>
#include <vector>
#include <time.h>
#include "code.h"
#include "response.h"

#ifndef MASTERMIND_H
#define MASTERMIND_H

using namespace std;


class mastermind
//Stores the response to a guess (number correct and number incorrect)
{
public:
    mastermind(int n, int m);
    mastermind();
    void getSecretCode(const int input);
    code humanGuess();
    response getResponse(const code &A);
    bool isSolved(const response &A);
    void playGame();
private:
    int codeLength;
    int digitRange;
}; // End of response class
#endif //MASTERMIND_H