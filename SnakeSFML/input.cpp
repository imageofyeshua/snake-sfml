#include "engine.h"

void Engine::input()
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

			// Direction
			if (event.key.code == Keyboard::Up)
			{
				addDirection(Direction::UP);
			}
			else if (event.key.code == Keyboard::Down)
			{
				addDirection(Direction::DOWN);
			}
			else if (event.key.code == Keyboard::Left)
			{
				addDirection(Direction::LEFT);
			}
			else if (event.key.code == Keyboard::Right)
			{
				addDirection(Direction::RIGHT);
			}
		}
	}
}

void Engine::addDirection(int newDirection)
{
	if (directionQueue.empty())
	{
		directionQueue.emplace_back(newDirection);
	}
	else
	{
		if (directionQueue.back() != newDirection)
		{
			directionQueue.emplace_back(newDirection);
		}
	}
}