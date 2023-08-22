#pragma once

#include"SFML/Graphics.hpp"
#include"backEndWorld.h"
#include"tetrimino.h"

using namespace sf;


const int CELL_SIZE = 30;
const Color BLOCK_COLOR[] = { Color::Cyan,Color::Blue,Color(255,165,0),Color::Yellow,Color::Green,Color(128,0,128),Color::Red };


class Draw {
public:
	
	void drawBackGroundWorld(RenderWindow& Window,RectangleShape BackgroundCell) {
		BackgroundCell.setFillColor(Color(23, 23, 23));
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				BackgroundCell.setPosition(CELL_SIZE * j, CELL_SIZE * i);
				Window.draw(BackgroundCell);
			}
		}
	}

	void drawWorld(RenderWindow& Window,RectangleShape Cell,World world) {
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				if (world.getValueAtIndex(i, j)) {
					Cell.setFillColor(BLOCK_COLOR[world.getValueAtIndex(i, j) - 1]);
					Cell.setPosition(j * CELL_SIZE, i * CELL_SIZE);
					Window.draw(Cell);
				}
			}
		}
	}

	void drawBlock(RenderWindow& Window,RectangleShape Cell,Block* blocks[], int blockKind,int currentX,int currentY) {
		Cell.setFillColor(Color(BLOCK_COLOR[blockKind]));
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (blocks[blockKind]->getValueAtIndex(i, j)) {
					Cell.setPosition(Vector2f((currentX + j) * CELL_SIZE, (currentY + i) * CELL_SIZE));
					Window.draw(Cell);
				}
			}
		}
	}
};