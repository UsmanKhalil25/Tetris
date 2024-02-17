#include"text.h"


CustomText::CustomText(const int rows,const int cols,const int cellSize,const int resX,const int resY) {
	if (!font.loadFromFile("fonts/norwester.otf"))
		std::cout << "Font not loaded\n";

	this->preview.setFont(font);
	this->preview.setString("Next Block");
	this->preview.setPosition((cellSize * cols * 1.3) -resX/4 , cellSize * rows * 0.18);
	this->hold.setFont(font);
	this->hold.setString("Hold");
	this->hold.setPosition((cellSize * cols * 1.3) -resX/4, cellSize * rows * 0.54);

	this->playerTitleText.setFont(font);
	this->playerTitleText.setString("Player: ");
	this->playerTitleText.setPosition(resX/3+ cellSize * cols * 1.3, cellSize * rows * 0.18);
	this->scoreTitleText.setFont(font);
	this->scoreTitleText.setString("Score: ");
	this->scoreTitleText.setPosition(resX / 3 + cellSize * cols * 1.3, cellSize * rows * 0.36);
	this->levelTitleText.setFont(font);
	this->levelTitleText.setString("Level: ");
	this->levelTitleText.setPosition(resX / 3 + cellSize * cols * 1.3, cellSize * rows * 0.54);
	this->lineTitleText.setFont(font);
	this->lineTitleText.setString("Lines: ");
	this->lineTitleText.setPosition(resX / 3 + cellSize * cols * 1.3, cellSize * rows * 0.72);
	this->escape.setFont(font);
	this->escape.setString("Esc to Exit");
	this->escape.setCharacterSize(20);
	this->escape.setPosition(resX / 3 + cellSize * cols * 1.6, cellSize * rows * 0.93);

}

void CustomText::setText(std::string name, const int score, const int level, const int line,const int rows,const int cols,const int cellSize,const int resX,const int resY,sf::Color color) {
	this->escape.setFillColor(color);
	this->preview.setFillColor(color);
	this->hold.setFillColor(color);

	this->playerTitleText.setFillColor(color);
	this->playerNameText.setFillColor(color);
	this->scoreTitleText.setFillColor(color);
	this->scoreText.setFillColor(color);
	this->levelTitleText.setFillColor(color);
	this->levelText.setFillColor(color);
	this->lineTitleText.setFillColor(color);
	this->lineText.setFillColor(color);


	this->playerNameText.setFont(font);
	this->playerNameText.setString(name);
	this->playerNameText.setCharacterSize(25);
	this->playerNameText.setPosition(resX/3 + cellSize * cols * 1.3, cellSize * rows * 0.26);

	this->scoreText.setFont(font);
	this->scoreText.setString(std::to_string(score));
	this->scoreText.setPosition(resX/3+ cellSize * cols * 1.3, cellSize * rows * 0.42);
	this->scoreText.setCharacterSize(25);

	this->levelText.setFont(font);
	this->levelText.setString(std::to_string(level));
	this->levelText.setPosition(resX / 3 + cellSize * cols * 1.3, cellSize * rows * 0.60);
	this->levelText.setCharacterSize(25);

	this->lineText.setFont(font);
	this->lineText.setString(std::to_string(line));
	this->lineText.setPosition(resX / 3 + cellSize * cols * 1.3, cellSize * rows * 0.78);
	this->lineText.setCharacterSize(25);

}
void CustomText::drawText(sf::RenderWindow& window) {
	window.draw(this->playerTitleText);
	window.draw(this->playerNameText);
	window.draw(this->scoreTitleText);
	window.draw(this->scoreText);
	window.draw(this->levelTitleText);
	window.draw(this->levelText);
	window.draw(this->lineTitleText);
	window.draw(this->lineText);
	window.draw(this->escape);
	window.draw(this->hold);
	window.draw(this->preview);

}
