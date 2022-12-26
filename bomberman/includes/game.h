#pragma once
#include "main.h"

class game
{
public:
	game();
	void update();
	void handleinputs();
	void updatemap();
	void updatebots();
	void checkcollisions();
	void check_victory();
	void display();
	~game();
	
private:
	
protected:
	std::vector<player *> players;
	std::vector<bot *> bots;
	std::vector<bomb *> bombs;
	std::vector<bonus *> bonuses;
	carte map;
	
};
