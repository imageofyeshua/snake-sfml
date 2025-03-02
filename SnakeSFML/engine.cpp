#include "engine.h"

const sf::Time Engine::TimePerFrame = seconds(1.f / 60.f);
const float windowWidth = 500;
const float windowHeight = 800;

Engine::Engine()
{
	resolution = Vector2f(windowWidth, windowHeight);
	window.create(VideoMode(resolution.x, resolution.y), "Snake", Style::Default);
	window.setFramerateLimit(FPS);
}

void Engine::run()
{
	// Main loop - Runs until the window is closed
	while (window.isOpen())
	{
		input();
		draw();
	}
}
