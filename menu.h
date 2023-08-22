#pragma once

#include<SFML/Graphics.hpp>

using namespace sf;

#define numberOfItems 3

class Menu {
private:
	int currentOption;
	Font font;
	Text options[numberOfItems];

public:
	Menu() {
		this->currentOption = -1;
		font.loadFromFile("fonts/norwester.otf");
		for (int i = 0; i < numberOfItems; i++) {
			options[i].setFont(font);
			options[i].setFillColor(Color::White);
			options[i].setOutlineColor(Color(255, 16, 240));
			options[i].setOutlineThickness(2);
			options[i].setCharacterSize(50);
		}
		
		options[0].setString("Play");
		options[0].setPosition(25 * 8.5 , 25 * 20 * 0.3);
		options[1].setString("Highscore");
		options[1].setPosition(25 * 8.5 , 25 * 20 * 0.5);
		options[2].setString("Exit");
		options[2].setPosition(25 * 8.5, 25 * 20 * 0.7);

		

	}

	void moveUp() {
		if (currentOption - 1 >= 0){
			options[currentOption].setFillColor(Color::White);
			options[currentOption].setOutlineColor(Color(255, 16, 240));

			currentOption--;
			if (currentOption <= -1)
				currentOption = 2;
			options[currentOption].setFillColor(Color(255, 16, 240));
			options[currentOption].setOutlineColor(Color::White);
		
		}

	}
	void moveDown() {
		if (currentOption + 1 <= numberOfItems) {
			options[currentOption].setFillColor(Color::White);
			options[currentOption].setOutlineColor(Color(255, 16, 240));

			currentOption++;

			if (currentOption >= 3)
				currentOption = 0;
			options[currentOption].setFillColor(Color(255, 16, 240));
			options[currentOption].setOutlineColor(Color::White);

		}
			
		

	}

	void draw(RenderWindow& Window) {
		for (int i = 0; i < numberOfItems; i++)
			Window.draw(this->options[i]);
		
	}



	int selectedOption() {
		return currentOption;
	}
};

