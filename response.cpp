/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 1, Part B
 * Contains code class and all necessary functions (checkCorrect, checkIncorrect).
 * Implements code class to run a game of Mastermind.
 */

#include "response.h"

response::response(){
    correctGuess = 0;
    incorrectGuess = 0;
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

bool operator == (const response &A, const response &B) {
    //B correct re
    if((A.getCorrectNumbers() == B.getCorrectNumbers()) && (A.getIncorrectNumbers() == B.getIncorrectNumbers()))
        return true;
    else
        return false;
}

ostream& operator << (ostream &out, response&A){
    out << "Correct Digits:   " << A.getCorrectNumbers() << endl << "Misplaced Digits: " << A.getIncorrectNumbers() << endl;
    return out;
}