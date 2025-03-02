#include "snakesection.h"

const float snakeSizeX = 20.f;
const float snakeSizeY = 20.f;

SnakeSection::SnakeSection(Vector2f startPosition)
{
	section.setSize(Vector2f(snakeSizeX, snakeSizeY));
	section.setFillColor(Color::Green);
	section.setPosition(startPosition);
}

Vector2f SnakeSection::getPosition()
{
	return position;
}

void SnakeSection::setPosition(Vector2f newPosition)
{
	position = newPosition;
}

RectangleShape SnakeSection::getShape()
{
	return section;
}

void SnakeSection::update()
{
	section.setPosition(position);
}
