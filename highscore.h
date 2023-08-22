#pragma once
#include<SFML/Graphics.hpp>
#include<fstream>
#include<string>

using  namespace sf;
using namespace std;

class Highscore {
private:
	Text highscoreText;
	Text scores[5];
	Text names[5];
	Text escape;
	Font font;
	ifstream fin;
	ofstream fout;

public:
	Highscore() {
		this->font.loadFromFile("fonts/norwester.otf");
		highscoreText.setFont(font);
		highscoreText.setFillColor(Color::White);
		highscoreText.setString("Highscores");
		highscoreText.setPosition(25 * 7, 25 * 20*0.12 );
		highscoreText.setCharacterSize(50);
		highscoreText.setOutlineColor(Color(255, 16, 240));
		highscoreText.setOutlineThickness(3);

		escape.setCharacterSize(20);
		escape.setFont(font);
		escape.setFillColor(Color::White);
		escape.setString("Esc to Exit");
		escape.setOutlineColor(Color(255, 16, 240));
		escape.setOutlineThickness(3);
		escape.setPosition(CELL_SIZE * COL * 1.6, CELL_SIZE * ROW * 0.93);
		



		for (int i = 0; i < 5; i++) {
			names[i].setFont(font);
			names[i].setFillColor(Color::White);
			names[i].setPosition(25 * 7, 25 * 20 * 0.15 * (2 + i));
			names[i].setOutlineColor(Color(255, 16, 240));
			names[i].setOutlineThickness(3);
			names[i].setCharacterSize(32);
			scores[i].setFont(font);
			scores[i].setFillColor(Color::White);
			scores[i].setPosition(Vector2f(25 * 10* 1.5, 25 * 20 *0.15 * (2 + i)));
			scores[i].setOutlineColor(Color(255, 16, 240));
			scores[i].setOutlineThickness(3);
			scores[i].setCharacterSize(32);

		}

		fin.open("scores.txt", ios::in);
		int indexNames = 0;
		int indexScores = 0;
		bool check = 0;

		if (fin.is_open()) {
			while (!fin.eof()) {
				string temp = "";
				getline(fin, temp, '\$');
				if (indexNames < 5 || indexScores<5) {
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


	}

	void drawScore(RenderWindow& Window) {
		Window.draw(highscoreText);
		Window.draw(escape);
		for (int i = 0; i < 5; i++) {
			Window.draw(this->names[i]);
			Window.draw(this->scores[i]);

		}
	}

	void sorter(string scoresArr[],string namesArr[], const int size) {
		for (int i = 1; i < size; i++) {
			for (int j = 0; j < size - i; j++) {
				if (stoi(scoresArr[j]) < stoi(scoresArr[j + 1])) {
					swap(scoresArr[j], scoresArr[j + 1]);
					swap(namesArr[j], namesArr[j + 1]);

				}
			}
		}
	}

	void newScore(const string score,const string name) {
		string scoresArr[6];
		string namesArr[6];
		int indexNames = 0;
		int indexScores = 0;
		bool check = 0;
		fin.open("scores.txt", ios::in);
		if (fin.is_open()) {
			while (!fin.eof()) {
				string temp = "";
				getline(fin, temp, '\$');
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

		sorter(scoresArr,namesArr, 6);
		for (int i = 0; i < 5; i++) {
			this->scores[i].setString(scoresArr[i]);
			this->names[i].setString(namesArr[i]);
		}

		check = 0;
		fout.open("scores.txt", ios::out);
		if (fout.is_open()) {
			for (int i = 0; i < 5; i++) {
				if (!check) {
					fout << namesArr[i] << '$';
					check = 1;
					i--;
				}
				else {
					fout << scoresArr[i] << '$';
					check = 0;
				}

			}
		}
		fout.close();
	}

};