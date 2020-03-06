#pragma once
#include"Screen.h"

class MainMenuScreen : public Screen
{
private:
	sf::Font m_font;
	sf::Text m_menuText;
	EScreen m_switchScreen = EScreen::mainmenu;

	void input();
	void update(float dt);
	void draw(RenderWindow* rw);
public:
	MainMenuScreen();
	void render(float dt, RenderWindow* rw) override;
	void dispose() override;
	bool shouldSwitchScreen() override;
	EScreen getSwitchScreen() override;
};
