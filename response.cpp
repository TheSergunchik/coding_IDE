/*
 * By: Sergey Petrushkevich
 * Project 1, Part A
 * Contains code class and all necessary functions (checkCorrect, checkIncorrect).
 * Implements code class to run a game of Mastermind.
 */

#include "response.h"

response::response(){
    correctGuess = 0;
    incorrectGuess = 0;
}

void response::setCorrectResponse(const int input) {
    correctGuess = input;
}
void response::setIncorrectResponse(const int input) {
    incorrectGuess = input;
}

int response::getCorrectResponse() const {
    return correctGuess;
}

int response::getIncorrectResponse() const {
    return incorrectGuess;
}

bool operator == (const response &A, const response &B) {
    //B correct re
    if((A.getCorrectResponse() == B.getCorrectResponse()) && (A.getIncorrectResponse() == B.getIncorrectResponse()))
        return true;
    else
        return false;
}

ostream & operator << (ostream &out, response&A){
    out << "Correct Digits:   " << A.getCorrectResponse() << endl << "Misplaced Digits: " << A.getIncorrectResponse() << endl;
    return out;
}