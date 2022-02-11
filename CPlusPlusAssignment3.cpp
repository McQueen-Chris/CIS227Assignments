/* Names: Christian McQueen, Fernando Alvarez, Robert Duffing
*  Date: 02-10-2022
*
*
* Select a word from the array and put it into a container.
* Give the user the option to select words from the file, or the set you created last week
* Read the word list from an external file (Create a separate read file class)
* Prompt the user to guess the letters in the word. Provide feedback if the user is correct or not.
* Exit the program on user request


*/

#include<iostream>
#include<string>
#include "Header.h"
#include <fstream>
#include <vector>
using namespace std;
char exitOrRepeat = 'y';

//function runs the word game
void mainProgram() {
    string userInput;
    string myArray[12]; 
    vector<char> myVector;
    string stringToVector; //string to be split into a vector of characters
    int numberChoice;
    char yesOrNo = 'n';
    char userGuess;
    int guesses = 3; //number of guesses
    bool containsChar = false;
    bool gameWon = false;
    string revealedWord = "*****";

    //populates array from file
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
    //creates object
    wordListFromFile myObject(myArray[0], myArray[1], myArray[2], myArray[3], myArray[4], myArray[5], myArray[6],
        myArray[7], myArray[8], myArray[9], myArray[10], myArray[11]);

    //user chooses mystery word from list
    cout << "Choose the mystery word. Please enter an integer 1 -12" << endl;
    cin >> numberChoice;

    switch (numberChoice) {
    case 1:
        stringToVector = myArray[0];
        for (unsigned int i = 0; i < stringToVector.length(); i++) {
            myVector.push_back(stringToVector[i]);
            
        }
        break;
    case 2:
        stringToVector = myArray[1];
        for (unsigned int i = 0; i < stringToVector.length(); i++) {
            myVector.push_back(stringToVector[i]);
            
        }
        break;
    case 3:
        stringToVector = myArray[2];
        for (unsigned int i = 0; i < stringToVector.length(); i++) {
            myVector.push_back(stringToVector[i]);
            
        }
        break;
    case 4:
        stringToVector = myArray[3];
        for (unsigned int i = 0; i < stringToVector.length(); i++) {
            myVector.push_back(stringToVector[i]);
        }
        break;
    case 5:
        stringToVector = myArray[4];
        for (unsigned int i = 0; i < stringToVector.length(); i++) {
            myVector.push_back(stringToVector[i]);
        }
        break;
    case 6:
        stringToVector = myArray[5];
        for (unsigned int i = 0; i < stringToVector.length(); i++) {
            myVector.push_back(stringToVector[i]);
        }
        break;
    case 7:
        stringToVector = myArray[6];
        for (unsigned int i = 0; i < stringToVector.length(); i++) {
            myVector.push_back(stringToVector[i]);
        }
        break;
    case 8:
        stringToVector = myArray[7];
        for (unsigned int i = 0; i < stringToVector.length(); i++) {
            myVector.push_back(stringToVector[i]);
        }
        break;
    case 9:
        stringToVector = myArray[8];
        for (unsigned int i = 0; i < stringToVector.length(); i++) {
            myVector.push_back(stringToVector[i]);
        }
        break;
    case 10:
        stringToVector = myArray[9];
        for (unsigned int i = 0; i < stringToVector.length(); i++) {
            myVector.push_back(stringToVector[i]);
        }
        break;
    case 11:
        stringToVector = myArray[10];
        for (unsigned int i = 0; i < stringToVector.length(); i++) {
            myVector.push_back(stringToVector[i]);
        }
        break;
    case 12:
        stringToVector = myArray[11];
        for (unsigned int i = 0; i < stringToVector.length(); i++) {
            myVector.push_back(stringToVector[i]);
        }
        break;
    }
    //Main game portion
    while (guesses > 0 && gameWon == false) {
        cout << "Guess a letter:" << endl;
        cout << "Enter a letter from a-z" << endl;
        cout << "You can make 3 wrong guesses before it is game over" << endl;
        cout << revealedWord << endl;  
        cin >> userGuess;
        for (unsigned int i = 0; i < myVector.size() && i < revealedWord.length(); i++) {
            if (myVector[i] == userGuess) {
                containsChar = true;
                revealedWord[i] = userGuess;
            }

        }

        if (containsChar == true) {
            cout << revealedWord << endl;
            cout << "guesses left: " << guesses << endl;
            if (revealedWord == stringToVector) {
                gameWon = true;
                cout << " Congratulations, you have won the game!" << endl;
            }
        }
        else if (containsChar == false) {
            cout << "The word does not contain the letter " << userGuess << "." << endl;
            guesses--;
            cout << "guesses left: " << guesses << endl;
        }

        if (guesses == 0) {
            cout << "Sorry, game over." << endl;
        }

    }
}






int main() {
    
    char exitOrRepeat = 'y'; //the loop that determines if the program runs again or exits, set to run at least once
    do {
        cout << "Welcome to the Word Game!" << endl;
        cout << " " << endl;
        mainProgram();
        cout << "Would you like to play again? Enter 'y' to start over or 'n' to exit" << endl;
        cin >> exitOrRepeat;
    } while (exitOrRepeat == 'y');
    cout << "Goodbye!" << endl;
    exit(0);

}