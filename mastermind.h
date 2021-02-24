/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 1, Part B
 * Contains mastermind class and the functions to run a game.
 * Implements code and response classes.
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
//Stores the mastermind game functions
{
public:
    mastermind(int n, int m);
    mastermind();
    void printSecretCode();
    void printGuessCode(code &guess);
    code humanGuess();
    response getResponse(const code &A);
    bool isSolved(const response &guessResponse, const response &correctResponse);
    void playGame();
private:
    code secretCode;
    int codeLength;
    int digitRange;
}; // End of response class
#endif //MASTERMIND_H