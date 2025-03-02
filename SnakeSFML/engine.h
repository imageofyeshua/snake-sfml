#pragma once

#include "snakesection.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>
#include <deque>

using namespace sf;
using namespace std;

class Engine
{
private:
	// Window
	Vector2f resolution;
	RenderWindow window;
	const unsigned int FPS = 60;
	static const Time TimePerFrame;

	vector<SnakeSection> snake;

	int snakeDirection;
	deque<int> directionQueue; // queue for direction key presses
	int speed;

	Time timeSinceLastMove;

public:
	enum Direction { UP, RIGHT, DOWN, LEFT };
	Engine();

	void input();

	void addDirection(int newDirection);
	void update();

	void draw();

	void newSnake();
	void addSnakeSection();

	// the main loop will be in the run function
	void run();
};
