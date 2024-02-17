#pragma once

#include <SFML/Graphics.hpp>
//including classes
#include"state.h"
#include"menu.h"
#include"game.h"
#include"score.h"


class Engine {
private:
	sf::RenderWindow mWindow;
	float mResolutionX;
	float mResolutionY;

	const int FPS = 60;
	const sf::Time FRAME_TIME = sf::seconds(1.0f / FPS);

	std::string mName;
	int mScore;
	// user defined classes objects
	MainState mainState;
	Menu menu;
	Game* game;
	Highscore highscore;
	bool mTheme; // using 0 for dark theme and 1 for light theme
	int mDifficulty;

private:
	void mainLoop();
	void pollEvents();
	void render();
	void update();

public:
	Engine();
	void run();

};