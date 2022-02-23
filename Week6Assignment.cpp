/* Names: Christian McQueen, Fernando Alvarez, Robert Duffing
*  Date: 02-21-2022
*  
* Modify Assignment 4 to include Set and/or Multiset Containers.
* Provide an option for the user to enter their username and use it in player output.
* Add a point system for your hangman game. Points per letter, points for a win.
*/

#include <iostream>
#include <string>
#include "Week5Header.h"
#include <fstream>
#include <vector>
#include <deque>
#include <map>
using namespace std;

char exitOrRepeat = 'y';
string username;
int userPoints = 0;

//Function runs the word game
void mainProgram() {
    string myArray[12]; 
    string stringToVector; //String to be split into a vector of characters, holds the user choice word from 1-12
    int numberChoice;
    char yesOrNo = 'n';
    char userGuess;
    int guesses = 3; //Number of guesses
    bool containsChar = false;
    bool gameWon = false;
    string revealedWord = "*****";
    deque<unsigned short int> intDeque; //Deque that stores the
    char userChar; //Character variable used when asking user if they want a hint

    deque<unsigned short int>::iterator iteratorDeque; //Points to memory location
    deque<unsigned short int>::reverse_iterator reverseDeque;


    //Populates array from file
    fstream myFile;
    myFile.open("myWordList.txt", ios::in);
    int i = 0;

    if (myFile.is_open()) {
        string line;
        while (i <12 && myFile >> myArray[i]) {
            i++;
        }
       
        myFile.close();
    }


    //Creates object
    wordListFromFile myObject(myArray[0], myArray[1], myArray[2], myArray[3], myArray[4], myArray[5], myArray[6],
        myArray[7], myArray[8], myArray[9], myArray[10], myArray[11]);

    //User chooses mystery word from list
    cout << "Choose the mystery word. Please enter a number 1 - 12" << endl;
    cin >> numberChoice;

    switch (numberChoice) {
    case 1:
        stringToVector = myArray[0];
        for (unsigned int i = 0; i < stringToVector.length(); i++) {
            intDeque.push_back(stringToVector[i]);
            
        }
        break;
    case 2:
        stringToVector = myArray[1];
        for (unsigned int i = 0; i < stringToVector.length(); i++) {
            intDeque.push_back(stringToVector[i]);
            
        }
        break;
    case 3:
        stringToVector = myArray[2];
        for (unsigned int i = 0; i < stringToVector.length(); i++) {
            intDeque.push_back(stringToVector[i]);
            
        }
        break;
    case 4:
        stringToVector = myArray[3];
        for (unsigned int i = 0; i < stringToVector.length(); i++) {
            intDeque.push_back(stringToVector[i]);
        }
        break;
    case 5:
        stringToVector = myArray[4];
        for (unsigned int i = 0; i < stringToVector.length(); i++) {
            intDeque.push_back(stringToVector[i]);
        }
        break;
    case 6:
        stringToVector = myArray[5];
        for (unsigned int i = 0; i < stringToVector.length(); i++) {
            intDeque.push_back(stringToVector[i]);
        }
        break;
    case 7:
        stringToVector = myArray[6];
        for (unsigned int i = 0; i < stringToVector.length(); i++) {
            intDeque.push_back(stringToVector[i]);
        }
        break;
    case 8:
        stringToVector = myArray[7];
        for (unsigned int i = 0; i < stringToVector.length(); i++) {
            intDeque.push_back(stringToVector[i]);
        }
        break;
    case 9:
        stringToVector = myArray[8];
        for (unsigned int i = 0; i < stringToVector.length(); i++) {
            intDeque.push_back(stringToVector[i]);
        }
        break;
    case 10:
        stringToVector = myArray[9];
        for (unsigned int i = 0; i < stringToVector.length(); i++) {
            intDeque.push_back(stringToVector[i]);
        }
        break;
    case 11:
        stringToVector = myArray[10];
        for (unsigned int i = 0; i < stringToVector.length(); i++) {
            intDeque.push_back(stringToVector[i]);
        }
        break;
    case 12:
        stringToVector = myArray[11];
        for (unsigned int i = 0; i < stringToVector.length(); i++) {
            intDeque.push_back(stringToVector[i]);
        }
        break;
    }

    //Main game portion -- 3 incorrect guesses allowed!
    while (guesses != 0 && gameWon == false) {
        cout << "Guess a letter from a-z. You are allowed 3 incorrect guesses before it's game over: " << endl;
        cout << revealedWord << endl; //Outputs the asterisks hiding the word
        cin >> userGuess; //Takes user guess

        for (unsigned int i = 0; i < intDeque.size() && i < revealedWord.length(); i++) {
            if (intDeque[i] == userGuess) {
                containsChar = true;
                revealedWord[i] = userGuess; //Takes the correct letter and replaces the position asterisk with the letter
                userPoints++;
            }
        }

        if (containsChar == true) {
            cout << revealedWord << endl;
            cout << "Guesses left: " << guesses << endl;
            if (revealedWord == stringToVector) {
                gameWon = true;
                cout << " Congratulations, " << username << "! You have won the game! Final points: " << userPoints << endl;
            }
        }
        else if (containsChar == false) {
            cout << "The word does not contain the letter " << userGuess << "." << endl;
            guesses--;
            cout << "Guesses left: " << guesses << endl;

            if (guesses > 0 && guesses < 3) {

                cout << "Would you like a hint? Y/N" << endl;
                cin >> userChar;

                if (userChar == 'Y') {
                    
                    cout << "Your letter was: " << userGuess << endl;
                    cout << "The correct letter is x letters away from " << userGuess << endl;
                }
            }

        }

        if (guesses == 0) {
            cout << "Sorry, game over." << endl;
        }

    }
}

int main() {
    
    char exitOrRepeat = 'y'; //The loop that determines if the program runs again or exits, set to run at least once
    do {
        cout << "Welcome to the Word Game! Please enter a username: " << endl;
        cin >> username;
        cout << "Hello, " << username << "!" << endl;

        map<string, int> siMapPlayers;
        siMapPlayers[username] = 1;
        map<string, int>::iterator siIterator = siMapPlayers.begin();


        while (siIterator != siMapPlayers.end()) {
    
            cout << endl << siIterator->first;
            cout << endl << siIterator->second;
            siIterator++;
        }

        mainProgram();
        cout << "Would you like to play again? Enter 'y' to start over or 'n' to exit" << endl;

        cin >> exitOrRepeat;

    } while (exitOrRepeat == 'y');

    cout << "Goodbye!" << endl;
    exit(0);

}