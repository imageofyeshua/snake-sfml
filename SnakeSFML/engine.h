#pragma once

#include "snakesection.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>

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

public:
	Engine();

	void input();

	void draw();

	void newSnake();
	void addSnakeSection();

	// the main loop will be in the run function
	void run();
};
