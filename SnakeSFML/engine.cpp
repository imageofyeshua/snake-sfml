#include "engine.h"

const sf::Time Engine::TimePerFrame = seconds(1.f / 60.f);
const float windowWidth = 500;
const float windowHeight = 800;

Engine::Engine()
{
	resolution = Vector2f(windowWidth, windowHeight);
	window.create(VideoMode(resolution.x, resolution.y), "Snake", Style::Default);
	window.setFramerateLimit(FPS);
	newSnake();
}

void Engine::newSnake()
{
	snake.clear();
	snake.emplace_back(Vector2f(100, 100));
	snake.emplace_back(Vector2f(80, 100));
	snake.emplace_back(Vector2f(60, 100));
}

void Engine::addSnakeSection()
{
	Vector2f newSectionPosition = snake[snake.size() - 1].getPosition();
	snake.emplace_back(newSectionPosition);
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
