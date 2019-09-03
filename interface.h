#ifndef MENU_H
#define MENU_H

class interface {
	private:
	int scoreX;
	int scoreO;
	public:
	interface();
	void startMenu();
	void scoreScreen();
	void resetScores();
	void updateScores(char);
};

#endif