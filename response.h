/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 1, Part B
 * Contains response class and all necessary functions.
 * Implements response class to store the number of correct and incorrect guesses.
 */

#include <iostream>
#include <vector>
#include <time.h>

#ifndef RESPONSE_H
#define RESPONSE_H

using namespace std;

class response
{
public:
    response();
    response(int correctG, int incorrectG);
    void setCorrectNumbers(const int input);
    void setIncorrectNumbers(const int input);
    int getCorrectNumbers() const;
    int getIncorrectNumbers() const;

    //An overloaded operator == that compares responses and returns true if they are equal (global)
    friend bool operator == (const response &A, const response &B);

    //An overloaded operator << that prints a response (global).
    friend ostream& operator << (ostream &out, response &A);

private:
    int correctGuess;
    int incorrectGuess;
}; // End of response class
#endif //RESPONSE_H