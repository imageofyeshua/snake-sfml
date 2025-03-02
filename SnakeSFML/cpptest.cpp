#include "cpptest.h"

const float windowWidth = 500.f;
const float windowHeight = 800.f;
const float positionX = 100.f;
const float positionY = 100.f;

Test::Test()
{
	resolution = Vector2f(windowWidth, windowHeight);
	window.create(VideoMode(resolution.x, resolution.y), "Test", Style::Default);
	window.setFramerateLimit(FPS);
}

void Test::setText()
{
	text.setFont(font);
	text.setString("Hello, Daniel Park");
	text.setPosition(Vector2f(positionX, positionY));
	text.setCharacterSize(24);
	text.setFillColor(Color::White);
}

void Test::setFont()
{
	if (!font.loadFromFile("../resources/font/arial.ttf"))
	{
		cout << "Font loading error!" << endl;
	}
}

void Test::input()
{
	Event event{};

	while (window.pollEvent(event))
	{
		// Window closed
		if (event.type == Event::Closed)
		{
			window.close();
		}

		// Handle keyboard input
		if (event.type == Event::KeyPressed)
		{
			// Quit
			if (event.key.code == Keyboard::Escape)
			{
				window.close();
			}
		}
	}
}

void Test::draw()
{
	window.clear(Color::Black);

	window.draw(text);

	window.display();
}

void Test::run()
{
	while (window.isOpen())
	{
		input();
		setFont();
		setText();
		draw();
	}
}
