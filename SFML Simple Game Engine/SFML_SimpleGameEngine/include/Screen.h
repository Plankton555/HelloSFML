#pragma once
#include <SFML/Graphics.hpp>
#include "EScreen.h"

using namespace sf;

class Screen
{
public:
	virtual void render(float dt, RenderWindow* rw) = 0;
	virtual void dispose() = 0;
	virtual bool shouldSwitchScreen() = 0;
	virtual EScreen getSwitchScreen() = 0;
};

