#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

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

public:
	Engine();

	void input();

	void draw();

	// the main loop will be in the run function
	void run();
};
