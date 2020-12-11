#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

const int MAX_TRIES = 7;
int letterFill(char, string, string&);

int main()
{
    string name;
    int worngGusses = 0;
    char letter;
    string word;
    string words[] = {
        "india",
        "nepal",
        "malaysia",
        "philippines",
        "australia",
        "indonesia",
        "oman",
        "iran",
        "ethiopia",
        "america"};
    srand(time(NULL));   //
    int n = rand() % 10; //choosing and coping a word form arrays of words randomly
    word = words[n];     //

    string unknown(word.length(), '*'); // Initilizing a secret word with *

    cout << "\n\nWelcome to hangman Guess a country Name";
    cout << "\n\nEach letter is represented by a star.";
    cout << "\n\nYou have to type only one letter in one try";
    cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    while (worngGusses < MAX_TRIES)
    {
        cout << "\n\n"
             << unknown;
        cout << "\n\nGuess a letter: ";
        cin >> letter;

        // Fill secret word with letter if the guess is correct,
        // otherwise increment the number of wrong guesses.
        if (letterFill(letter, word, unknown) == 0)
        {
            cout << endl
                 << "Whoops! That letter isn't in there!" << endl;
            worngGusses++;
        }
        else
        {
            cout << endl
                 << "You found a letter... Isn't that good!" << endl;
        }

        cout << "You have " << MAX_TRIES - worngGusses;
        cout << " guesses left " << endl; // No of gusses left..

        // Check if user guessed the word.
        if (word == unknown)
        {
            cout << word << endl;
            cout << "Yeah! you got it!";
            break;
        }
    }
    if (worngGusses == MAX_TRIES)
    {
        cout << "\n Sorry you lose " << endl;
        cout << "The word was: " << word << endl;
    }
    cin.ignore();
    cin.get();
    return 0;
}

// Take a one character guess and the secret word
// fill in the unfinished guessword
// Returns number of characters matched
// returns zero if the character is already guessed

int letterFill(char guess, string secretword, string &guessword)
{
    int i;
    int matches = 0;
    int len = secretword.length();
    for (i = 0; i < len; i++)
    {

        if (guess == guessword[i])
        {
            return 0;
        }

        if (guess == secretword[i])
        {
            guessword[i] = guess;
            matches++;
        }
    }
    return matches;
}




