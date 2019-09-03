#include "interface.h"
#include "gameplay.h"
#include <iostream>

using namespace std;

interface::interface() {
	scoreX = 0;
	scoreO = 0;
}

void interface::startMenu() {
	int input = 0;
	
	while (input != 4) {
		cout << endl;
		cout << "Welcome to the TicTacToe menu." << endl;
		cout << "1. Play a match" << endl;
		cout << "2. View player scores" << endl;
		cout << "3. Reset player scores" << endl;
		cout << "4. Quit" << endl;
		cout << "Enter a number: " << endl;
	
		cin >> input;
	
		if(input == 1) {
			gameplay run;
			run.displayBoxes();
			updateScores(run.runGame());
		} else if(input == 2) {
			scoreScreen();
		} else {
			resetScores();
		}
	}
	
	cout << endl << "Goodbye" << endl;
	
	return;
}

void interface::scoreScreen() {
	cout << endl;
	cout << "Player X score: " << scoreX << endl;
	cout << "Player O score: " << scoreO << endl;
	
	return;
}

void interface::resetScores() {
	scoreX = 0;
	scoreO = 0;

	scoreScreen();
	cout << "Both player scores have been reset to 0." << endl;
	
	return;
}

void interface::updateScores(char player) {
	if(player == 'X') {
		++scoreX;
	} else if(player == 'O') {
		++scoreO;
	} else {
		return;
	}
	return;
}


