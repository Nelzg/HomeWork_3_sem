#pragma once
#include "MaterialPoint.h"
#include <SFML\Graphics.hpp>

class Ball : public MaterialPoint
{
public:
	float radius;
	int type;
	sf::CircleShape circle;
};

