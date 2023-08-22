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
#ifndef HANGMAN_H
#define HANGMAN_H
#include <string>
#include <vector>
#include "player.h"

using std::vector;
using std::string;

class Hangman
{
public:
    const static int ALPHABET_SIZE = 26; //const set rows for Alphabet
    const static int ASCII_ROWS = 7;
    const static int ASCII_COLS = 8;
    Hangman(string filename, string username);
    int selectGameLevel();
    int generateRandomNumber();
    string selectRandomWord(int random_number);
    void loadWordList(std::string filename);
    void startGame();
    void printMessage(string message, bool printTop = true, bool printBottom = true);
    void drawHangman(int guessCount = 0);
    void resetAvailableLetters();
    void printAsciiMessage(string message);
    void printAvailableLetters(string taken);
    bool checkWin(string wordToGuess, string guessesSoFar);
    bool processResults(string wordToGuess, int guessAttempts, bool hasWon);
    void setDifficultyLevel(unsigned diffLevel);
    unsigned getDifficultyLevel();
    void setMaxAllowedAttempts(unsigned allowedAttempts);
    unsigned getMaxAllowedAttempts();
    unsigned attemptsMadeSoFar(std::string wordToGuess, std::string guessesSoFar);


private:
    Player player;
    vector<string> wordVector;
    unsigned difficultyLevel;
    unsigned maxAllowedAttempts;
    char alphabetArray[ALPHABET_SIZE + 1];

    constexpr static char G[ASCII_ROWS][ASCII_COLS]={
                                                                                                                        "  #### ", //Row=0
                                                                                                                        " #     ", //Row=1
                                                                                                                        " #     ", //Row=2
                                                                                                                        " # ### ", //Row=3
                                                                                                                        " #   # ", //Row=4
                                                                                                                        " #   # ", //Row=5
                                                                                                                        "  ###  "  //Row=6
                                                    };
    constexpr static char A[ASCII_ROWS][ASCII_COLS] = {
                                                                                                                       "  ###  ", //Row=0
                                                                                                                       " #   # ",     //Row=1
                                                                                                                       " #   # ",     //Row=2
                                                                                                                       " ##### ",     //Row=3
                                                                                                                       " #   # ",     //Row=4
                                                                                                                       " #   # ",     //Row=5
                                                                                                                       " #   # "       //Row=6
    };
    constexpr static char M[ASCII_ROWS][ASCII_COLS] = {
                                                                                                                       " #   # ",  //Row=0
                                                                                                                       " ## ## ",//Row=1
                                                                                                                       " # # # ",//Row=2
                                                                                                                       " # # # ",//Row=3
                                                                                                                       " #   # ",//Row=4
                                                                                                                       " #   # ",//Row=5
                                                                                                                       " #   # "  //Row=6

    };
    constexpr static char E[ASCII_ROWS][ASCII_COLS] = {
                                                                                                                        " ##### ", //Row=0
                                                                                                                        " #     ", //Row=1
                                                                                                                        " #     ", //Row=2
                                                                                                                        " ##### ", //Row=3
                                                                                                                        " #     ", //Row=4
                                                                                                                        " #     ", //Row=5
                                                                                                                        " ##### "  //Row=6

    };
    constexpr static char O[ASCII_ROWS][ASCII_COLS] = {
                                                                                                                        "  ###  ", //Row=0
                                                                                                                        " #   # ", //Row=1
                                                                                                                        " #   # ", //Row=2
                                                                                                                        " #   # ", //Row=3
                                                                                                                        " #   # ", //Row=4
                                                                                                                        " #   # ", //Row=5
                                                                                                                        "  ###  "  //Row=6

    };

    constexpr static char V[ASCII_ROWS][ASCII_COLS]={                                                                       " #   # ", //Row=0
                                                                                                                            " #   # ", //Row=1
                                                                                                                            " #   # ", //Row=2
                                                                                                                            " #   # ", //Row=3
                                                                                                                            " #   # ", //Row=4
                                                                                                                            "  # #  ", //Row=5
                                                                                                                            "   #   "}; //Row=6


    constexpr static char R[ASCII_ROWS][ASCII_COLS] = {
                                                                                                                            "  ###  ", //Row 0
                                                                                                                            " #   # ", //Row=1
                                                                                                                            " #   # ", //Row=2
                                                                                                                            " ####  ", //Row=3
                                                                                                                            " #  #  ", //Row=4
                                                                                                                            " #   # ", //Row=5
                                                                                                                            " #   # "  //Row=6

    };
    constexpr static char Y[ASCII_ROWS][ASCII_COLS] = {
                                                                                                                            " #   # ", //Row = 0
                                                                                                                            " #   # ", //Row=1
                                                                                                                            " #   # ", //Row=2
                                                                                                                            "  ###  ", //Row=3
                                                                                                                            "   #   ", //Row=4
                                                                                                                            "   #   ", //Row=5
                                                                                                                            "   #   "  //Row=6

    };
    constexpr static char U[ASCII_ROWS][ASCII_COLS] = {
                                                                                                                            " #   # ", //Row = 0
                                                                                                                            " #   # ",//Row=1
                                                                                                                            " #   # ",//Row=2
                                                                                                                            " #   # ",//Row=3
                                                                                                                            " #   # ",//Row=4
                                                                                                                            " #   # ",//Row=5
                                                                                                                            "  ###  "  //Row=6

    };
    constexpr static char W[ASCII_ROWS][ASCII_COLS] = {
                                                                                                                            " #   # ", //Row =0
                                                                                                                            " #   # ", //Row=1
                                                                                                                            " #   # ", //Row=2
                                                                                                                            " # # # ", //Row=3
                                                                                                                            " # # # ", //Row=4
                                                                                                                            " ## ## ", //Row=5
                                                                                                                            " #   # "  //Row=6

    };
    constexpr static char N[ASCII_ROWS][ASCII_COLS] = {
                                                                                                                            " #   # ", //Row=0
                                                                                                                            " ##  # ", //Row=1
                                                                                                                            " # # # ", //Row=2
                                                                                                                            " # # # ", //Row=3
                                                                                                                            " #  ## ", //Row=4
                                                                                                                            " #  ## ", //Row=5
                                                                                                                            " #   # "  //Row=6

    };
    constexpr static char exclamation[ASCII_ROWS][ASCII_COLS] = {
                                                                                                                               "  ##   ", //Row=0
                                                                                                                               "  ##   ", //Row=1
                                                                                                                               "  ##   ", //Row=2
                                                                                                                               "  ##   ", //Row=3
                                                                                                                               "  ##   ", //Row=4
                                                                                                                               "       ", //Row=5
                                                                                                                               "  ##   "  //Row=6

    };
    constexpr static char space[ASCII_ROWS][ASCII_COLS] = {
                                                                                                                                "       ", //Row=0
                                                                                                                                "       ", //Row=1
                                                                                                                                "       ", //Row=2
                                                                                                                                "       ", //Row=3
                                                                                                                                "       ", //Row=4
                                                                                                                                "       ", //Row=5
                                                                                                                                "       "  //Row=6

    };

    };

#endif // HANGMAN_H

