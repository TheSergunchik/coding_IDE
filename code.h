/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 1, Part B
 * Contains code class and all necessary functions (checkCorrect, checkIncorrect).
 * Implements code class to run a game of Mastermind.
 */

#include <iostream>
#include <vector>
#include <time.h>

#ifndef CODE_H
#define CODE_H

using namespace std;

class code
{
public:
    code(int n, int m);
    void randomizeCode();
    int checkCorrect(const code &guessVector) const;
    int checkIncorrect(const code &guessVector) const;
    void resetVector();
    void addElement(int value);
    int getElement(int index) const;
    void printVector();
    void enterElements();
private:
    int codeLength;
    int digitRange;
    vector<int> codeVector;
}; // End of code class
#endif //CODE_H