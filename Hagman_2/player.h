/*************************************************************
 *  Instructor's Name: Mrs. Vernelle Sylvester                                 *
 *  Group Members: Lianni Mathews, Jason Fortik                         *
 *  Project: Hangman                                                                          *
 *  Description: Hangman utilizes object oriented programming    *
 *  to create an object that stores the statistics that are being        *
 *  generated and also uses classes to separate the functions and  *
 *  their declarations as libraries outside the main file                   *
 *  Due Date: March 25,2021                                                             *
 *************************************************************/
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using std::string;

typedef unsigned int uint; // defined primitive type to "uint"

class Player {
private:
    int guessArray[10]; //array to store the amount of user guesses
    char username[20];  //array to store the username
    uint difficultyLevel; //dificulty level the user inputs
    static const uint MAX_DIFICULTY_LEVEL = 3; //the max dificulty that can be set

public:
    //parameterized constructor
    Player(string username, uint level = 1);
    //member functions
    void setDifficultyLevel(uint level);
    int getDifficultyLevel();
    string getUsername();
    void setUsername(string name);
    void setGuesses(unsigned int numGuesses);
    string generateStatistics();
    void resetGuessesArray();

};

#endif // PLAYER_H
