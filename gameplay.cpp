#include "gameplay.h"
#include "interface.h"
#include <cstdlib>
#include <iostream>

using namespace std;

gameplay::gameplay() {
    turn = 1;
	for(int i = 0; i < 9; ++i) {
		grid[i] = " ";
	}
	player = ' ';
}

char gameplay::runGame() {
	char tied = 't';
	char first;
	char second;

	//if else branch determines which player goes first randomly
	if(rand() % 2 == 0) {
		first = 'X';
		second = 'O';
	} else {
		first = 'O';
		second = 'X';
	}
	cout << endl << first << " is going first." << endl;
    
    while(turn != 10) {
		playerTurn(first, second);
		
		checkSpaceTaken();
		
		displayBoxes();
		
        ++turn;
		
		if(checkWin()) {
			cout << "Turn: " << turn << endl;
			cout << "Player " << player << " has won this game." << endl;
			return player;
		}
    }
	
	cout << "Turn: " << turn << endl;
	cout << "Both players tied this game." << endl;
	return tied;
}

void gameplay::displayBoxes() const {
    for(int i = 0; i < 9; ++i) {
		cout << grid[i];
		if(((i + 1) % 3) == 0) {
			cout << endl;
		} else {
			cout << " | ";
		}
	}
}

void gameplay::playerTurn(char first, char second) {
	if(turn % 2 == 0) {
		setPlayer(second);
	} else {
		setPlayer(first);
	}
	cout << "Turn: " << turn << endl;
	cout << "Input player " << player << "'s move(1-9): " << endl;
	
	return;
}

//checks if the space is taken or not
void gameplay::checkSpaceTaken() {
	bool availiableSpace = false;
	int input;
	
	while (!(availiableSpace)) {
		cin >> input;
		--input;
		availiableSpace = isValidSpace(input);
	}
	
	return;
}

//checks if the space is on the TicTacToe grid
bool gameplay::isValidSpace(int input) {
	if((input > -1) && (input < 9)) {
		if(grid[input] != " ") {
			cout << "The space is already taken. Choose a new space." << endl;
			return false;
		} else {
			grid[input] = getPlayer();
			return true;
		}
	} else {
		cout << "Invalid space. Choose a new space." << endl;
		return false;
	}
}

void gameplay::setPlayer(char XO) {
	player = XO;
	return;
}

char gameplay::getPlayer() {
	return player;
}

bool gameplay::checkWin() {
	//for loop below checks for horizontal row wins
	for(int i = 0; i < 3; ++i) {
		if((grid[0 + (i * 3)] == grid[1 + (i * 3)]) && (grid[1 + (i * 3)] == grid[2 + (i *3 )]) && (grid[i * 3] != " ")) {
			return true;
		}
	}
	
	//for loop below checks for vertical row wins
	for(int i = 0; i < 3; ++i) {
		if((grid[i] == grid[i + 3]) && (grid[i + 3] == grid[i + 6]) && (grid[i] != " ")) {
			return true;
		}
	}
	
	//for loop below checks for diagonal row wins
	if(grid[4] != " ") {
		if(((grid[0] == grid[4]) && (grid[4] == grid[8])) || ((grid[2] == grid[4]) && (grid[4] == grid[6]))) {
			return true;
		}
	}
	
	return false;
}

