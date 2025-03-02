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
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
		}
	}
}