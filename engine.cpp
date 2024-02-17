#include "engine.h"


Engine::Engine():mResolutionX(1280.0f),mResolutionY(720.0f), mainState(MainState::Menu), menu(mResolutionX, mResolutionY),game(new Game(mResolutionX,mResolutionY)),mScore(0),mName(""),highscore(mResolutionX,mResolutionY),mTheme(0),mDifficulty(1) {
	mWindow.create(sf::VideoMode(mResolutionX, mResolutionY), "Tetris", (sf::Style::Close));
	mWindow.setVerticalSyncEnabled(true);
	mWindow.setFramerateLimit(FPS);
}


void Engine::run(){
	mainLoop();
}

void Engine::mainLoop(){
	sf::Clock clock;
	sf::Time elapsed = sf::Time::Zero;
	while (mWindow.isOpen()) {
		pollEvents();
		elapsed += clock.restart();
		while (elapsed >= FRAME_TIME) {
			elapsed -= FRAME_TIME;
			update();
		}
		render();
	}
}

void Engine::pollEvents(){
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		if (event.type == sf::Event::Closed|| mainState == MainState::Exit) {
			mWindow.close();
		}
		if (mainState == MainState::Menu)
			menu.handleEvent(event, mainState,mScore,mName,mTheme,mDifficulty);
		else if (mainState == MainState::Game)
			game->handleEvent(event, mainState,mScore,mName,highscore);
	}

}

void Engine::render(){
	mWindow.clear(sf::Color::Black);
	if (mainState == MainState::Menu)
		menu.draw(mWindow, mainState,mScore,mName,highscore);
	else if (mainState == MainState::Game)
		game->draw(mWindow, mainState,mTheme,mScore,mName);
	mWindow.display();

}

void Engine::update(){
	if (mainState == MainState::Exit)
		mWindow.close();
	else if (mainState == MainState::Menu) {
		menu.update(mainState,mScore,mName,mTheme,mDifficulty);
		if (game != nullptr) {
			delete game;
			game = nullptr;
		}
	}
	else if (mainState == MainState::Game) {
		if (game == nullptr) {
			game = new Game(mResolutionX, mResolutionY);
		}
		game->update(mainState, mScore, mName,mDifficulty,highscore);

	}
}


