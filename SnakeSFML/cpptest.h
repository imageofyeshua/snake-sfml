#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

using namespace sf;
using namespace std;

class Test
{
private:
	Vector2f resolution;
	RenderWindow window;
	const unsigned int FPS = 60;
	static const Time TimePerFrame;

	Text text;
	Font font;

public:
	Test();
	void setFont();
	void setText();
	void input();
	void draw();
	void run();
};
