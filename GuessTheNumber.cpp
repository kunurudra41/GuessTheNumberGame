#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void playGame() {
    int numberToGuess, playerGuess;
    const int maxTries = 5;
    int tries = 0;

    //Initialize random seed
    srand(static_cast<unsigned>(time(0)));
    numberToGuess = rand() % 100 + 1;//Random number between 1 and 100
    
    //output screen / game home page
    cout << "Welcome to 'Guess the Number'!" << endl;
    cout << "I'm thinking of a number between 1 and 100." << endl;
    cout << "You have " << maxTries << " attempts to guess it." << endl;

    //used while condition and iffelse condition for internal ui
    while (tries < maxTries) {
        cout << "\nEnter your guess: ";
        cin >> playerGuess;

        tries++;

        if (playerGuess == numberToGuess) {
            cout << "Congratulations! You guessed the number in " << tries << " tries." << endl;
            return;
        } else if (playerGuess < numberToGuess) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Too high! Try again." << endl;
        }

        cout << "Attempts left: " << maxTries - tries << endl;
    }

    cout << "\nSorry, you've used all your attempts. The number was: " << numberToGuess << endl;
}

//restart game feature
int main() {
    char playAgain;

    do {
        playGame();
        cout << "\nWould you like to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing! Goodbye." << endl;
    return 0;
}