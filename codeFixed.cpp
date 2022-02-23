

#include<iostream>
#include<string>
#include "Header.h"
#include <fstream>
#include <vector>
#include <deque>
using namespace std;
char exitOrRepeat = 'y';

//function runs the word game
void mainProgram() {
    string userInput;
    string myArray[12];
    deque<char> myDeque;
    string stringToDeque; //string to be split into a vector of characters
    int numberChoice;
    char yesOrNo = 'n';
    char userGuess;
    int guesses = 3; //number of guesses
    bool containsChar;
    bool gameWon = false;
    string revealedWord = "*****";
    int correctGuess =0;
    int incorrectGuess = 0;
    int points =0;
    int wins; //number of times the player has won
    int losses; // number of times that the player has lost the game.

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
        stringToDeque = myArray[0];
        for (unsigned int i = 0; i < stringToDeque.length(); i++) {
            myDeque.push_back(stringToDeque[i]);

        }
        break;
    case 2:
        stringToDeque = myArray[1];
        for (unsigned int i = 0; i < stringToDeque.length(); i++) {
            myDeque.push_back(stringToDeque[i]);

        }
        break;
    case 3:
        stringToDeque = myArray[2];
        for (unsigned int i = 0; i < stringToDeque.length(); i++) {
            myDeque.push_back(stringToDeque[i]);

        }
        break;
    case 4:
        stringToDeque = myArray[3];
        for (unsigned int i = 0; i < stringToDeque.length(); i++) {
            myDeque.push_back(stringToDeque[i]);
        }
        break;
    case 5:
        stringToDeque = myArray[4];
        for (unsigned int i = 0; i < stringToDeque.length(); i++) {
            myDeque.push_back(stringToDeque[i]);
        }
        break;
    case 6:
        stringToDeque = myArray[5];
        for (unsigned int i = 0; i < stringToDeque.length(); i++) {
            myDeque.push_back(stringToDeque[i]);
        }
        break;
    case 7:
        stringToDeque = myArray[6];
        for (unsigned int i = 0; i < stringToDeque.length(); i++) {
            myDeque.push_back(stringToDeque[i]);
        }
        break;
    case 8:
        stringToDeque = myArray[7];
        for (unsigned int i = 0; i < stringToDeque.length(); i++) {
            myDeque.push_back(stringToDeque[i]);
        }
        break;
    case 9:
        stringToDeque = myArray[8];
        for (unsigned int i = 0; i < stringToDeque.length(); i++) {
            myDeque.push_back(stringToDeque[i]);
        }
        break;
    case 10:
        stringToDeque = myArray[9];
        for (unsigned int i = 0; i < stringToDeque.length(); i++) {
            myDeque.push_back(stringToDeque[i]);
        }
        break;
    case 11:
        stringToDeque = myArray[10];
        for (unsigned int i = 0; i < stringToDeque.length(); i++) {
            myDeque.push_back(stringToDeque[i]);
        }
        break;
    case 12:
        stringToDeque = myArray[11];
        for (unsigned int i = 0; i < stringToDeque.length(); i++) {
            myDeque.push_back(stringToDeque[i]);
        }
        break;
    }
    //Main game portion
    while (guesses > 0 && gameWon == false) {
       
        cout << "Guess a letter:" << endl;
        cout << "Enter a letter from a-z" << endl;
        
        cout << revealedWord << endl;
        cin >> userGuess;
        for (unsigned int i = 0; i < myDeque.size() && i < revealedWord.length(); i++) {
            if (userGuess == myDeque[i]) {
                
                revealedWord[i] = userGuess;
                
                
            }

            
           
            
        }
        if (stringToDeque.find(userGuess) != string::npos){
            cout<<"You have guessed the letter correctly and gained 1 point"<<endl;
            points = points + 1;
            cout << "Points: " << points << endl;
        }
        else {
            cout << "You have guessed incorrectly and lost 1 point" << endl;
            points = points - 1;
            guesses = guesses - 1;
            cout << "Points: " << points << endl;
        }
        cout << "Wrong Guesses Left: " << guesses << endl;

        if (guesses == 0) {
            cout << "Sorry, game over." << endl;
        }
        if (revealedWord == stringToDeque) {
            gameWon = true;
            cout << " Congratulations, you have won the game!" << endl;
        }
        
         
    }
}





    int main() {
        //TODO: Introduce program
        char exitOrRepeat = 'y'; //the loop that determines if the program runs again or exits, set to run at least once
        do {
            mainProgram();
            cout << "Would you like to play again? Enter 'y' to start over or 'n' to exit" << endl;
            cin >> exitOrRepeat;
        } while (exitOrRepeat == 'y');

        exit(0);

    }