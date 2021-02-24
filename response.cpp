/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 1, Part B
 * Function definition for response class.
 */

#include "response.h"

response::response()
// Default constructor for response class.
{
    correctGuess = 0;
    incorrectGuess = 0;
}

response::response(int correctG, int incorrectG)
// Special constructor, meant to instantiate a 'correct' response so future responses could be compared against it.
{
    correctGuess = correctG;
    incorrectGuess = incorrectG;
}

void response::setCorrectNumbers(const int input) {
    correctGuess = input;
}
void response::setIncorrectNumbers(const int input) {
    incorrectGuess = input;
}

int response::getCorrectNumbers() const {
    return correctGuess;
}

int response::getIncorrectNumbers() const {
    return incorrectGuess;
}

bool operator == (const response &A, const response &B)
// Checks to see if all members in response A == all members in response B.
{

    if((A.getCorrectNumbers() == B.getCorrectNumbers()) && (A.getIncorrectNumbers() == B.getIncorrectNumbers()))
        return true;
    else
        return false;
}

ostream& operator << (ostream &out, response&A)
// Overloaded operator for cout - prints correct and incorrect numbers.
{
    out << "Correct Digits:   " << A.getCorrectNumbers() << endl << "Misplaced Digits: " << A.getIncorrectNumbers() << endl;
    return out;
}