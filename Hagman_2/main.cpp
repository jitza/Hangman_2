#include "player.h"
#include "hangman.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    string username;
    cout<<"Please enter your username: ";
    cin>>username;
    Hangman game("wordlist.txt",username);
    game.startGame();

    return 0;
}
