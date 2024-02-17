#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class CustomText {
private:
	sf::Text playerTitleText;
	sf::Text playerNameText;
	sf::Text levelTitleText;
	sf::Text levelText;
	sf::Text scoreTitleText;
	sf::Text scoreText;
	sf::Text lineTitleText;
	sf::Text lineText;
	sf::Text escape;
	sf::Text preview;
	sf::Text hold;
	sf::Font font;
public:
	CustomText(const int rows, const int cols, const int cellSize, const int resX, const int resY);
	void setText(std::string name,const int score, const int level, const int line,const int rows,const int cols,const int cellSize,const int resX,const int resY,sf::Color color);
	void drawText(sf::RenderWindow& window);
};