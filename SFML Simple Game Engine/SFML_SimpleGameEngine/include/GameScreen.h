#pragma once
#include"Screen.h"
#include "Bob.h"

class GameScreen : public Screen
{
private:
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;
	Bob m_Bob;

	void input();
	void update(float dt);
	void draw(RenderWindow* rw);
public:
	GameScreen();
	void render(float dt, RenderWindow* rw) override;
	void dispose() override;
	bool shouldSwitchScreen() override;
	EScreen getSwitchScreen() override;
};
