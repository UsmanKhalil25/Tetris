#pragma once
#include<SFML/Graphics.hpp>
#include<fstream>
#include<string>


class Highscore {
private:
	sf::Text highscoreText;
	sf::Text scores[5];
	sf::Text names[5];
	sf::Text escape;
	sf::Font font;
	std::ifstream fin;
	std::ofstream fout;
public:
	Highscore(float resX, float resY);
	void drawScore(sf::RenderWindow& Window);
	void sorter(std::string scoresArr[], std::string namesArr[], const int size);
	void newScore(const std::string score, const std::string name);

};