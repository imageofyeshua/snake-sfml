#include "engine.h"

void Engine::update()
{
	// Update snake position
	if (timeSinceLastMove.asSeconds() >= seconds(1.f / float(speed)).asSeconds())
	{
		Vector2f thisSectionPosition = snake[0].getPosition();
		Vector2f lastSectionPosition = thisSectionPosition;

		if (!directionQueue.empty())
		{
			switch (snakeDirection)
			{
			case Direction::UP:
				if (directionQueue.front() != Direction::DOWN)
				{
					snakeDirection = directionQueue.front();
				}
				break;
			case Direction::DOWN:
				if (directionQueue.front() != Direction::UP)
				{
					snakeDirection = directionQueue.front();
				}
				break;
			case Direction::LEFT:
				if (directionQueue.front() != Direction::RIGHT)
				{
					snakeDirection = directionQueue.front();
				}
				break;
			case Direction::RIGHT:
				if (directionQueue.front() != Direction::LEFT)
				{
					snakeDirection = directionQueue.front();
				}
				break;
			}
			directionQueue.pop_front();
		}

		// Update the snake's head position
		switch (snakeDirection)
		{
		case Direction::RIGHT:
			snake[0].setPosition(Vector2f(thisSectionPosition.x + 20, thisSectionPosition.y));
			break;
		case Direction::DOWN:
			snake[0].setPosition(Vector2f(thisSectionPosition.x, thisSectionPosition.y + 20));
			break;
		case Direction::LEFT:
			snake[0].setPosition(Vector2f(thisSectionPosition.x - 20, thisSectionPosition.y));
			break;
		case Direction::UP:
			snake[0].setPosition(Vector2f(thisSectionPosition.x, thisSectionPosition.y - 20));
			break;
		}

		// Update the snake tail positions
		for (int s = 1; s < snake.size(); s++)
		{
			thisSectionPosition = snake[s].getPosition();
			snake[s].setPosition(lastSectionPosition);
			lastSectionPosition = thisSectionPosition;
		}

		// Run snake section update function
		for (auto& s : snake)
		{
			s.update();
		}

		// Reset the last move timer
		timeSinceLastMove = Time::Zero;
	} // End update snake position
}