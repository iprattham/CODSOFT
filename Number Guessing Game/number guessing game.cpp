#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Add this line to enable C++11 features if needed
#define nullptr NULL

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;
    int lowerBound = 1;
    int upperBound = 100;

    cout << "Number Guessing game by: Pratham Aggarwal\n" << endl;

    do {
        cout << "Guess the number (between " << lowerBound << " and " << upperBound << "): ";
        cin >> guess;

        attempts++;

        if (guess < randomNumber) {
            cout << "Too low! Try again." << endl;
            lowerBound = guess + 1; // Update the lower bound
        } else if (guess > randomNumber) {
            cout << "Too high! Try again." << endl;
            upperBound = guess - 1; // Update the upper bound
        } else {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts!" << endl;
        }
    } while (guess != randomNumber);

    return 0;
}

