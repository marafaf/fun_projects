#pragma once
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <vector>


enum classes
{
	bombes,
	bonus,
	player,
	bot,
};

class gameobject
{
public:
	gameobject();
	virtual void update() = 0;
	int getx() const;
	int gety() const;
	bool isalive() const;
	void setclass(classes);
	~gameobject();
	
private:
	
protected:
	
	int x;
	int y;
	bool alive;
	classes cl;
	
};

class characters : public gameobject
{
public:
	characters();
	virtual void update() = 0;
	virtual void move(int _x, int _y) = 0;
	virtual void attack() = 0;
	~characters();
private:
	
protected:
	int lifes;
	int bombs;
};

class player : public characters
{
public:
	player();
	void update() override;
	void move(int _x, int _y) override;
	void attack() override;
	~player();
private:
protected:
};

class bot : public characters
{
public:
	bot();
	void update() override;
	void move(int _x, int _y) override;
	void attack() override;
	~bot();
private:
	
protected:
	
};

class bonus : public gameobject
{
public:
	bonus();
	~bonus();
private:
protected:
	
};

class bomb : public gameobject
{
public:
	bomb();
	~bomb();
private:
	
protected:
	
};

class carte
{
public:
	carte();
	void update();
	bool istraversable(int x, int y);
	bool hasobject();
	~carte();

private:
	std::vector<std::vector<char>> cells;
};
