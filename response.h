/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 1, Part B
 * Contains code class and all necessary functions (checkCorrect, checkIncorrect).
 * Implements code class to run a game of Mastermind.
 */

#include <iostream>
#include <vector>
#include <time.h>

#ifndef RESPONSE_H
#define RESPONSE_H

using namespace std;


class response
//Stores the response to a guess (number correct and number incorrect)
{
public:
    response();
    void setCorrectResponse(const int input);
    void setIncorrectResponse(const int input);
    int getCorrectResponse() const;
    int getIncorrectResponse() const;

    //An overloaded operator == that compares responses and returns true if they are equal (global)
    friend bool operator == (const response &A, const response &B);

    //An overloaded operator << that prints a response (global).
    friend ostream & operator << (ostream &out, response&A);

private:
    int correctGuess;
    int incorrectGuess;
}; // End of response class
#endif //RESPONSE_H