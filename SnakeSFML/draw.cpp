#include "engine.h"

void Engine::draw()
{
	window.clear(Color::Black);

	// draw snake sections
	for (auto& s : snake)
	{
		window.draw(s.getShape());
	}

	window.display();
}