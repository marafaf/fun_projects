#include "../includes/game.h"


gameobject::gameobject(int _x, int _y)
{
	x = _x;
	y = _y;
	alive = true;
	return ;
}

gameobject::~gameobject()
{
}

int gameobject::getx() const
{
	return (x);
}

int gameobject::gety() const
{
	return (y);
}

bool gameobject::isalive() const
{
	return (alive);
}

void gameobject::setclass(classes a)
{
	cl = a;
}

std::string gameobject::getclass()
{
	std::string entitytype;
	switch(cl)
	{
	case bombes:
		entitytype = "bomb";
		break;
	case bonus:
		entitytype = "bonus";
		break;
	case player:
		entitytype = "player";
		break;
	case bot:
		entitytype = "bot";
		break;
	}
	return (entitytype);
}


int main(int ac, char **av)
{
	printf("%s\n", "Bomberman!");
	return (0);
}
