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
#include "hangman.h"
#include "player.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using std::string;
using std::cout;
using std::cin;
using std::ifstream;
using std::cout;
using std::endl;
using std::toupper;

//initialises the game by loading the word list, setting dificulty and "registering" the user
Hangman::Hangman(std::string filename, string username) : player(username)
{
    loadWordList(filename);
    int chosen_level = selectGameLevel();
    setDifficultyLevel(chosen_level);
}

void Hangman::loadWordList(std::string filename)
{
    string word;
    ifstream infile; //creates a file inputstream object used to connect to a text file
    infile.open (filename);//use the inputstream object to open file
    if (infile.is_open())//check if the file was successfully opened
    {
        while(!infile.eof())//while not at the end of file eof()
        {
            getline(infile, word);//read a line from the file and store it in the string variable, word
            wordVector.push_back(word);//insert string word into the vector
        }//repeat until the end of file is reached
        infile.close();//close the file once it has been processed
    }
    else //if you are here, it is because there was a problem opening the file
    {
        cout<<"Unable to open file, "<<filename<<endl; //notify the user that a problem has occurred
        cout<<"Hangman game will now terminate."<<endl;

        exit(-1);//terminate the program since no words could be loaded, making the game impossible
    }
}

//prompt for the user to choose dificulty level
int Hangman::selectGameLevel()
{
    int num = 0;
    do   //do-while to ensure user inputs a proper level
        {
            cout << "Please select a level" << endl
                 << "1: Easy" << endl
                 << "2: Normal" << endl
                 << "3: Hard" << endl;
            cout << ">>";
            cin >> num;
            system("cls"); //clears screen
        } while(num < 1 || num > 3); //evaluates whether the number is acceptable or not
    Hangman::setDifficultyLevel(num);
    return num;
}

// use to return a random number to correspond to a word within a range based on dificulty
int Hangman::generateRandomNumber()
{
    int level = getDifficultyLevel();
    std::srand(static_cast<unsigned int>(std::time(0)));
    if(level == 1)
        {
            int number_1 = rand();
            return (number_1 % 63) + 1;
        }
    else if (level == 2)
        {
            int number_2 = rand();
            number_2 %= 352;
            if(number_2<=63) //evaluates if the number is less than or equal to 65
            {
                number_2 = 63 + (number_2 % 287); //if it is then it will add to 63 to whatever is returned as a remainder from that number generated
            }
            return number_2;
        }
    else if(level == 3)
        {
            int number_3 = rand();
            number_3 %= 485;
            if(number_3<=351)//evaluates if the number is less than or equal to 351
            {
                number_3 = 351 + (number_3 % 113); //if it is then it will add to 351 to whatever is returned as a remainder from that number generated
            }
            return number_3;
        }
    return 1;
}

//selects a word by subscript of  the random number that was generated
string Hangman::selectRandomWord(int random_number)
{
    return wordVector[random_number];
}

//removes used letters in order to show the letters that are still available
void Hangman::resetAvailableLetters()
{
    int count = 0;
    for (char i = 'A'; i <= 'Z'; i++)
        {
            alphabetArray[count]= i;
            count++;
        }
}
//prints the starting message and the 'game'; updating as being played
void Hangman::printMessage(string message, bool printTop, bool printBottom)
{
    if (printTop)
        {
            cout << "+"<<  "---------------------------------" << "+ \n";
        }
    cout << "|";
    string::size_type free_spaces = 33 - message.length(); //allows the function to know the amount of available free spaces based on the size of the message
    bool iscentered = true;
    for (string::size_type i = 0; i < free_spaces; i++)
        {
            if(iscentered)
                {
                    cout << " "; //adds a space to the left
                    iscentered = false; //this makes the condition to go into the else statement
                }
            else
                {
                    message += " "; //this makes the condition reset in order to go into the if statement
                    iscentered = true; //adds a space to the right
                }
        }
    cout << message;
    cout << "|\n";
    if (printBottom)
        {
            cout << "+"<< "---------------------------------" << "+\n";
        }
}

void Hangman::drawHangman(int guessCount)
{ //these conditionals check wheter the guess count is greater than or equal to a value in order to draw a figure
    if (guessCount >= 1)
           printMessage("|", false, false);
       else
           printMessage("", false, false);

    if (guessCount >= 2)
        printMessage("|", false, false);
    else
        printMessage("", false, false);

    if (guessCount >= 3)
        printMessage("O", false, false);
    else
        printMessage("", false, false);

    if (guessCount == 4)
        printMessage("/  ", false, false);

    if (guessCount == 5)
        printMessage("/| ", false, false);

    if (guessCount >= 6)
        printMessage("/|\\", false, false);
    else
        printMessage("", false, false);

    if (guessCount >= 7)
        printMessage("|", false, false);
    else
        printMessage("", false, false);

    if (guessCount == 8)
        printMessage("/  ", false, false);

    if (guessCount >= 9)
        printMessage("/ \\", false, false);
    else
           printMessage("", false, false);

    if(guessCount == 0)
        return;
}

//set the dificulty of the game.
void Hangman::setDifficultyLevel(unsigned diffLevel)
{
    difficultyLevel = diffLevel;
    if (difficultyLevel == 1)
        {
            setMaxAllowedAttempts( 10 );
        }
    else if (difficultyLevel == 2)
        {
            setMaxAllowedAttempts( 13 );
        }
    else if (difficultyLevel == 3)
        {
            setMaxAllowedAttempts( 10 );
        }
}

//returns the dificulty
unsigned Hangman::getDifficultyLevel()
{
    return difficultyLevel;
}
//set the max attempts allows based on dificulty
void Hangman::setMaxAllowedAttempts(unsigned allowedAttempts)
{
    maxAllowedAttempts = allowedAttempts;
}
//returns the max attempts allowed
unsigned Hangman::getMaxAllowedAttempts()
{
    return maxAllowedAttempts;
}
//calculates the amounts of attempts made during the game.
unsigned Hangman::attemptsMadeSoFar(string wordToGuess, string guessesSoFar)
{
    unsigned int errors = 0;
    for (string::size_type i = 0; i  < guessesSoFar.length(); i++)
    {
         guessesSoFar[ i ] = tolower(guessesSoFar[ i ]);
         if ((wordToGuess.find(guessesSoFar[ i ])) == string::npos)
             {
                     ++errors;
             }
     }
    return errors;
}
//updates game while played by displaying the remaining letter that can be chosen
void Hangman::printAvailableLetters(string guessesSoFar)
{
    printMessage("Available Letters",true,false);
    string letters = "";
    for (int i = 0; i < ALPHABET_SIZE;i++)
        {
            for (string::size_type j = 0, l = guessesSoFar.length(); j < l; j++)
                {
                    if (guessesSoFar[ j ] == alphabetArray[ i ])
                        {
                            alphabetArray[ i ] = ' '; //"removes" the letters guessed
                        }
                }
            letters += alphabetArray[ i ];
        }
    printMessage(letters,false,true); //prints remaining letters
}

//prints the ending messages; modified by other function
void Hangman::printAsciiMessage(string message)
{
    string temp;
    for (string::size_type i = 0; i < 7; i++) //loops through the rows of the character that w is at
    {
        for(string::size_type w = 0; w < message.size(); w++) // iterates through the letter of the message in order to assign the characters from the array in the current row
            {
                for (string::size_type j = 0; j < 1; j++) // loops through once to populate the string based on the current letter at w
                    {//the conditionals check what letter is at w and populates the temp string with all the characters of the letter array at the column from the current row
                        if(message[ w ] == 'G')
                                {
                                    for (string::size_type l = 0; l < 7; l++)
                                            temp += Hangman::G[ i ] [ l ];
                                    break;
                                }
                        if(message[ w ] == 'A')
                                {
                                    for (string::size_type l = 0; l < 7; l++)
                                            temp += Hangman::A[ i ] [ l ];
                                    break;
                                }
                        if(message[ w ] == 'M')
                                {
                                        for (string::size_type l = 0; l < 7; l++)
                                            temp += Hangman::M[ i ] [ l ];
                                    break;
                                }
                        if(message[ w ] == 'E')
                            {
                                for (string::size_type l = 0; l < 7; l++)
                                        temp += Hangman::E[ i ] [ l ];
                                break;
                            }
                        if(message[ w ] == 'O')
                            {
                                for (string::size_type l = 0; l < 7; l++)
                                        temp += Hangman::O[ i ] [ l ];
                                break;
                            }
                        if(message[ w ] == 'V')
                            {
                                for (string::size_type l = 0; l < 7; l++)
                                        temp += Hangman::V[ i ] [ l ];
                                break;
                            }
                        if(message[ w ] == 'R')
                            {
                                for (string::size_type l = 0; l < 7; l++)
                                    temp += Hangman::R[ i ] [ l ];
                                break;
                            }
                        if(message[ w ] == 'Y')
                        {
                            for (string::size_type l = 0; l < 7; l++)
                                    temp += Hangman::Y[i] [l];
                            break;
                        }
                        if(message[ w ] == 'U')
                            {
                                for (string::size_type l = 0; l < 7; l++)
                                        temp += Hangman::U[ i ] [ l ];
                                break;
                            }
                        if(message[ w ] == 'W')
                            {
                                for (string::size_type l = 0; l < 7; l++)
                                        temp += Hangman::W[ i ] [ l ];
                                break;
                            }
                        if(message[ w ] == 'N')
                            {
                                for (string::size_type l = 0; l < 7; l++)
                                        temp += Hangman::N[ i ] [ l ];
                                break;
                            }
                        if(message[ w ] == '!')
                            {
                                for (string::size_type l = 0; l < 7; l++)
                                        temp += Hangman::exclamation[ i ] [ l ];
                                break;
                            }
                        if(message[ w ] == ' ')
                            {
                                for (string::size_type l = 0; l < 7; l++)
                                    temp += Hangman::space[i][l];
                                break;
                            }
                    }
            }
    temp += " \n";
    }
    cout<< temp;
}

//checks if the user guesses the entire word.
bool Hangman::checkWin(std::string wordToGuess, std::string guessesSoFar)
{
    string wordSoFar = "";
    string temp = "";
    string fix; //string that removes the extra spaces
    for (string::size_type t = 0, w = wordToGuess.length(); t < w; t++) //this for loop initializes the strings in order to have a string size
        {
            wordSoFar += " ";
            temp += "_ ";
        }
    for (string::size_type i = 0, l = wordToGuess.length(); i < l; i++)
        {
            wordToGuess[i] = toupper(wordToGuess[i]);
            for (string::size_type j = 0, x = guessesSoFar.length(); j < x; j++)
                    if(wordToGuess[ i ] == guessesSoFar[ j ])
                        {
                            string::size_type replace_char = temp.find( '_' , i + i); //finds the closest underscore at i * 2 location
                            temp[ replace_char ] = tolower(wordToGuess[ i ]); //this replaces the correct letter where the underscore at replace char is located
                            wordSoFar[ i ] = wordToGuess[ i ]; //this stores the uppercase word that is currently spelled out
                        }
        }
    fix = temp; //this will assign whatever is at temp with all the extra spaces
    for (string::size_type i = 0; i < fix.length(); i++) //this loop does the magic or erasing the empty spaces
    {
        if(isalpha(fix[ i ])) //evaluates whether the letter at fix length is alphabetic or not
            if(fix[ i + 1 ] == ' ') //further evaluates whether the value after i is within the array in order to prevent the null character from being replaced
                fix.erase( i + 1, 1 ); //removes 1 space at the location after an alphabetic character
    }
    printMessage(fix,false,true);
    if (wordSoFar == wordToGuess )
        return true;
    return false;
}

//prints corresponding results based on if the user wins or loses.
bool Hangman::processResults(string wordToGuess, int guessAttempts, bool hasWon)
{
    player.setGuesses(guessAttempts);
    string stats = player.generateStatistics();
    cout << stats;
    cout << "Word to guess was: " << wordToGuess << endl;
    if(hasWon)
//       cout<< "U won!\n";
       printAsciiMessage("YOU WON!");
    else
        printAsciiMessage("GAME OVER!");
//       cout<< "U Loose\n";
    char letter;
    cout << "Would you like to play again? Y/N \n"; //prompts the user to declare if they want to play another game
    cout << "> ";
    cin >> letter;
    if ( letter == 'y' || letter == 'Y' )
        {
            int difficultyLevel = selectGameLevel(); //prompts user to set a difficulty level
            player.setDifficultyLevel( difficultyLevel ); //calls player object function to also set the difficulty level
            return true; //if this conditional is called then it will return true to start game whenever this function is called
        }
    return false;
}
//after all the initializing is set this function starts and maintain the game.
void Hangman::startGame()
{
    string guessesMade;
    string wordToGuess;
    unsigned amountOfGuesses = 0;
    bool hasWon = false;
    bool playAgain = false;
    char currentLetter;
    std::srand( static_cast<unsigned int>( std::time(0) ) );
    do
    { //starts the game loop
        guessesMade = ""; //initialises guesses
        wordToGuess = ""; //initialises the word to guess
        int randNum = generateRandomNumber(); //recieves the random number
        string wordToGuess = selectRandomWord( randNum ); //choses the word to guess
        resetAvailableLetters(); //ensure that all the letters are available
        do //do while that execute the entire game.
        {
            system( "cls" ); //clears the screen
            printMessage( "HANGMAN" ,true ,true );
            drawHangman(amountOfGuesses);
            printAvailableLetters(guessesMade);
            printMessage( "Guess the word", false,true);
            printMessage(wordToGuess,false,true);
            hasWon = checkWin(wordToGuess,guessesMade);//checks whether the user has won
            if(hasWon)//breaks the nested do while loop if the user won
                {
                    break;
                }
            cout << ">>";
            cin >> currentLetter;
            currentLetter = toupper(currentLetter);
            if (guessesMade.find(currentLetter) == string::npos )//evaluates if the current letter has been used
                {
                    guessesMade += currentLetter;
                }
            amountOfGuesses = attemptsMadeSoFar(wordToGuess,guessesMade);
        } while(amountOfGuesses < getMaxAllowedAttempts());//evaluates whether the game should end
         playAgain = processResults(wordToGuess,amountOfGuesses,hasWon);  //calls the function in order to print the results and check whether the user wants to play again
         amountOfGuesses = 0; //resets the guesses to 0
    } while(playAgain); //evaluates whether the user wants to play again
    system("pause");
    getchar();
}

