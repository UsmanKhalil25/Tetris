#include"score.h"
#include<iostream>

Highscore::Highscore(float resX,float resY) {
	this->font.loadFromFile("fonts/norwester.otf");
	highscoreText.setFont(font);
	highscoreText.setFillColor(sf::Color::White);
	highscoreText.setString("Highscores");
	highscoreText.setPosition(resX / 2 - highscoreText.getString().getSize() * 10, 50.0f);
	highscoreText.setCharacterSize(50);
	highscoreText.setOutlineColor(sf::Color(255, 16, 240));
	highscoreText.setOutlineThickness(3);

	escape.setCharacterSize(20);
	escape.setFont(font);
	escape.setFillColor(sf::Color::White);
	escape.setString("Esc to Exit");
	escape.setOutlineColor(sf::Color(255, 16, 240));
	escape.setOutlineThickness(3);
	escape.setPosition(resX - 200.0f, resY- 100.0f);



	fin.open("scores.txt", std::ios::in);
	int indexNames = 0;
	int indexScores = 0;
	bool check = 0;

	if (fin.is_open()) {
		while (!fin.eof()) {
			std::string temp = "";
			std::getline(fin, temp);
			if (indexNames < 5 || indexScores < 5) {
				if (!check) {
					this->names[indexNames++].setString(temp);
					check = 1;
				}
				else {
					this->scores[indexScores++].setString(temp);
					check = 0;
				}

			}
		}
	}
	fin.close();




	for (int i = 0; i < 5; i++) {
		names[i].setFont(font);
		names[i].setFillColor(sf::Color::White);
		names[i].setPosition(resX / 3 , 100.0f+ (resY / 8 + i * resY / 10));
		names[i].setOutlineColor(sf::Color(255, 16, 240));
		names[i].setOutlineThickness(3);
		names[i].setCharacterSize(32);
		scores[i].setFont(font);
		scores[i].setFillColor(sf::Color::White);
		scores[i].setPosition(resX/3 +300.0f, 100.0f + (resY / 8 + i * resY / 10));
		scores[i].setOutlineColor(sf::Color(255, 16, 240));
		scores[i].setOutlineThickness(3);
		scores[i].setCharacterSize(32);

	}

}

void Highscore::drawScore(sf::RenderWindow& Window) {
	Window.draw(highscoreText);
	Window.draw(escape);
	for (int i = 0; i < 5; i++) {
		Window.draw(this->names[i]);
		Window.draw(this->scores[i]);

	}
}

void Highscore::sorter(std::string scoresArr[], std::string namesArr[], const int size) {
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (stoi(scoresArr[j]) < stoi(scoresArr[j + 1])) {
				swap(scoresArr[j], scoresArr[j + 1]);
				swap(namesArr[j], namesArr[j + 1]);

			}
		}
	}
}

void Highscore::newScore(const std::string score, const std::string name) {
	std::string scoresArr[6];
	std::string namesArr[6];
	int indexNames = 0;
	int indexScores = 0;
	bool check = 0;
	fin.open("scores.txt", std::ios::in);
	if (fin.is_open()) {
		while (!fin.eof()) {
			std::string temp = "";
			std::getline(fin, temp);
			if (indexNames < 5 || indexScores < 5) {
				if (!check) {
					namesArr[indexNames++] = temp;
					check = 1;
				}
				else {
					scoresArr[indexScores++] = temp;
					check = 0;
				}
			}

		}
	}
	fin.close();

	namesArr[5] = name;
	scoresArr[5] = score;

	sorter(scoresArr, namesArr, 6);
	for (int i = 0; i < 5; i++) {
		this->scores[i].setString(scoresArr[i]);
		this->names[i].setString(namesArr[i]);
	}

	check = 0;
	fout.open("scores.txt", std::ios::out);
	if (fout.is_open()) {
		for (int i = 0; i < 5; i++) {
			if (!check) {
				fout << namesArr[i] << '\n';
				check = 1;
				i--;
			}
			else {
				fout << scoresArr[i]<<'\n';
				check = 0;
			}

		}
	}
	fout.close();
}