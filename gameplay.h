#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <iostream>

using namespace std;


class gameplay {
   private:
    string playerXMoves[9];
    string playerOMoves[9];
    string grid[9];
    int turn;
    char player;
   public:
    gameplay();
    char runGame();
    void displayBoxes() const;
    void playerTurn(char, char);
    void checkSpaceTaken();
    bool isValidSpace(int);
    void setPlayer(char);
    char getPlayer();
    bool checkWin();
};

#endif
