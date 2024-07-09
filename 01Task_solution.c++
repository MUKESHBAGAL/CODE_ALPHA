#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()

using namespace std;

int main() {
    srand(time(0));  // seed for random number generation based on current time

    int secretNumber = rand() % 100 + 1;  // generate random number between 1 and 100
    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have chosen a number between 1 and 100. Try to guess it." << endl;

    do {
        cout << "Enter your guess (between 1 and 100): ";
        cin >> guess;
        attempts++;

        if (guess < secretNumber) {
            cout << "Too low! Try guessing a higher number." << endl;
        } else if (guess > secretNumber) {
            cout << "Too high! Try guessing a lower number." << endl;
        } else {
            cout << "Congratulations! You guessed the number " << secretNumber << " in " << attempts << " attempts." << endl;
        }
    } while (guess != secretNumber);

    return 0;
}
