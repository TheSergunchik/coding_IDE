/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 1, Part B
 * Contains code class and all necessary functions (checkCorrect, checkIncorrect).
 * Implements code class to run a game of Mastermind.
 */

#include "code.h"

code::code(int n, int m)
// Initializes each code object with a random vector code. Assigns the length of vector as well as the range of digits.
{

    codeLength = n;
    digitRange = m - 1;
    randomizeCode();
}

void code::randomizeCode()
// Uses 'time.h' file and srand to create a random seed. Produces randomized elements in the specified range.
{
    srand(time(NULL));

    for(int x = 0; x < codeLength; x++)
        //Adds a random value in specified range, 'codeLength' amount of times.
    {
        addElement((rand() % (digitRange + 1)));

    }
}

void code::resetVector()
// Clears all elements from vector, making size 0. New elements can now be added.
{
    codeVector.clear();
}

void code::addElement(int value)
// Adds an element to the vector.
{
    codeVector.push_back(value);
}

int code::getElement(int index) const
// Returns a single value from the code vector.
{
    return codeVector[index];
}

void code::printVector()
// Cycles through the entire length of the vector, printing out it's contents.
{
    for(int x = 0; x < codeLength; x++)
    {
        cout << codeVector[x] << ' ';
    }

    cout << endl;
}

int code::checkCorrect(const code &guessVector) const
// Returns the amount of correct digits in the correct place. Cycles through each element in the 'secret' code vector.
// Checks if the 'guess' vector has an identical digit in the same position. Uses a counter to keep track of correct
// digits present.
{
    int correctDigits = 0;

    for(int x = 0; x < codeLength; x++){
        if(codeVector[x] == guessVector.getElement(x))
        {
            correctDigits++;
        }
    }
    return correctDigits;
}

int code::checkIncorrect(const code &guessVector) const
// Returns the amount of digits in the wrong place. Cycles through each number in the digit range in both
// 'secret' and 'guess' vectors. Uses two counters to keep track of number of same-digit in both vectors. Also, checks
// for the amount of digits in the correct place. Subtracts correct digits from both counters. Finally, checks to
// see if number of digits is greater in 'secret' or 'guess' vector, and outputs number of digits in the wrong place.
{
    // This is the final counter, updated once through every number cycle.
    int incorrectDigits = 0;

    // Two counters used to keep track the amount of same-valued digits in each array at the wrong place.
    int numberCount = 0;
    int numberCountGuess = 0;


    for(int x = 0; x <= digitRange; x++)
        // Cycles through the entire digit range (instead of by index elements)
    {
        for(int y = 0; y < codeLength; y++)
            // Cycles through each element to count how many same-valued digits there are.
        {
            if(guessVector.getElement(y) == x)
            {
                numberCountGuess++;
            }

            if(codeVector[y] == x)
            {
                numberCount++;

                if(codeVector[y] == guessVector.getElement(y))
                    // If digits are in correct place, subtracts them from the counters.
                {
                    numberCount--;
                    numberCountGuess--;
                }
            }
        } // End of element cycle for-loop.

        if(numberCountGuess < numberCount)
            // Checks to see if the number of same-valued digits in 'guess' is less than in the 'secret' code
        {
            incorrectDigits += numberCountGuess;
        } else if (numberCountGuess >= numberCount)
            // If number of same-valued digits is more, bound it by amount of same-valued digits in the 'secret' code.
            // This is done because no digit can be counted more than once.
        {
            incorrectDigits += numberCount;
        }

        // Resets the counters and prepares them for the next digit-check.
        numberCount = 0;
        numberCountGuess = 0;

    } // End of 0-digitRange cycle for-loop.

    return incorrectDigits;
}

void code::enterElements()
// Asks user to fill the code vector through sequential inputs. Checks to see if the input is within range, and if not,
// user is asked to try inputting a value again.
{
    int element;
    cout << "Enter " << codeLength << " element values (0-" << digitRange << ")" << endl;

    for(int x = 0; x < codeLength; x++)
    {
        cin >> element;

        while(element < 0 || element > digitRange || !cin)
            // Error-trapping while-loop.
        {
            cin.clear();
            cin.ignore();
            cout << "-- Please enter a value between 0 and " << digitRange << "! --" << endl;
            cin >> element;
        }

        cout << " ";
        addElement(element);
    }

}
