#pragma once
#include<SFML/Graphics.hpp>


using namespace sf;
using namespace std;


class text {
private:
	Text playerTitleText;
	Text playerNameText;
	Text levelTitleText;
	Text levelText;
	Text scoreTitleText;
	Text scoreText;
	Text lineTitleText;
	Text lineText;
	Text escape;
	Font font;
public:
	text() {
		if (!font.loadFromFile("fonts/norwester.otf"))
			std::cout << "Font not loaded\n";
		this->playerTitleText.setFont(font);
		this->playerTitleText.setString("Player: ");
		this->playerTitleText.setPosition(CELL_SIZE * COL * 1.3, CELL_SIZE * ROW * 0.18);
		this->scoreTitleText.setFont(font);
		this->scoreTitleText.setString("Score: ");
		this->scoreTitleText.setPosition(CELL_SIZE * COL * 1.3, CELL_SIZE * ROW * 0.36);
		this->levelTitleText.setFont(font);
		this->levelTitleText.setString("Level: ");
		this->levelTitleText.setPosition(CELL_SIZE * COL * 1.3, CELL_SIZE * ROW * 0.54);
		this->lineTitleText.setFont(font);
		this->lineTitleText.setString("Lines: ");
		this->lineTitleText.setPosition(CELL_SIZE * COL * 1.3, CELL_SIZE * ROW * 0.72);
		this->escape.setFont(font);
		this->escape.setString("Esc to Exit");
		this->escape.setCharacterSize(20);
		this->escape.setPosition(CELL_SIZE * COL*1.6, CELL_SIZE*ROW * 0.93);
	}

	void setText(const string name, const int score, const int level,const int line) {
		this->playerNameText.setFont(font);
		this->playerNameText.setString(name);
		this->playerNameText.setCharacterSize(25);
		this->playerNameText.setPosition(CELL_SIZE * COL * 1.3, CELL_SIZE * ROW * 0.26);

		this->scoreText.setFont(font);
		this->scoreText.setString(to_string(score));
		this->scoreText.setPosition(CELL_SIZE * COL * 1.3, CELL_SIZE * ROW * 0.42);
		this->scoreText.setCharacterSize(25);

		this->levelText.setFont(font);
		this->levelText.setString(to_string(level));
		this->levelText.setPosition(CELL_SIZE * COL * 1.3, CELL_SIZE * ROW * 0.60);
		this->levelText.setCharacterSize(25);

		this->lineText.setFont(font);
		this->lineText.setString(to_string(line));
		this->lineText.setPosition(CELL_SIZE * COL * 1.3, CELL_SIZE * ROW * 0.78);
		this->lineText.setCharacterSize(25);


	}
	void drawText(RenderWindow& Window) {
		Window.draw(this->playerTitleText);
		Window.draw(this->playerNameText);
		Window.draw(this->scoreTitleText);
		Window.draw(this->scoreText);
		Window.draw(this->levelTitleText);
		Window.draw(this->levelText);
		Window.draw(this->lineTitleText);
		Window.draw(this->lineText);
		Window.draw(this->escape);


	}
};