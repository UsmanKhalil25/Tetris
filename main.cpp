////summary//
//// 1->Make window
//// 2->Draw Cell
//// 3->Draw Block(Tetrimino)
//// 4->Movement(Left,right and Down)
//// 5->Collision Detection
//// 6->Draw World
//// 7->Next Block
//// 8->Timer
//// 9->Block rotation
//// 10->Clear lines
//// 11->Rotation Check
//// 12->Make Windows Bigger and Add Player Name and Score
//// 13->Make Menu
//// 14->Make Menu sync wiht Game
//// 15->Make class for highscore
//// 16->Sync highscore with the game
//// 17-> Add Sounds
////summary//

 
 
#include<SFML/Graphics.hpp>
#include"tetrimino.h"
#include"backEndWorld.h"
#include"draw.h"
#include"text.h"
#include"menu.h"
#include"highscore.h"
#include"sound.h"


using namespace sf;

//
//ROW = 20 in backEndWorld.h
//COL = 10 in backEndWorld.h
//CELL_SIZE = 25 in draw.h
//Color Pallete defined in draw.h



bool checkBlock(Block*blocks[],World world,int currentX,int currentY,int blockKind) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (blocks[blockKind]->getValueAtIndex(i, j) == 0)
				continue;
			if (currentX + j < 0 || currentX + j >= COL || currentY + i >= ROW)//collision with wall and bottom
				return false;
			if (world.getValueAtIndex(currentY + i, currentX + j))//collosion with blocks (world's blocks)
				return false;
		}
	}
	return true;
}

void newBlock(int&currentX,int&currentY,int&blockKind) {
	blockKind = rand() % 7;
	currentX = COL / 2 -1;
	currentY = 0;
}

bool moveDown(Block *blocks[],World&world,int& currentX,int& currentY,int& blockKind,int&score,int &line,SoundPlay& soundPlay) {

	currentY++;
	if (checkBlock(blocks,world,currentX,currentY,blockKind) == false)// Block has hit bottom
	{
		currentY--;
		soundPlay.playCollisionSonud();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (blocks[blockKind]->getValueAtIndex(i, j)) {
					world.setValueAtIndex(currentY + i, currentX + j, blockKind + 1);
				}
			}
		}
		world.clearLines(score,line);

		 ///*start new block*/
		newBlock(currentX,currentY,blockKind);
		return false;
	}
	return true;
}


bool rotationCheck(Block* blocks[], int& currentX, int blockKind) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (blocks[blockKind]->getValueAtIndex(i, j) == 0)
				continue;
			if (currentX + j < 0) {
				currentX++;
				return false;
			}

			if (currentX + j >= 10) {
				currentX--;
				return false;
			}
		}
	}
	return true;
}



void play(Highscore& highscore,const string& name) {
	
	srand(time(0));
	RenderWindow playWindow(VideoMode(COL * CELL_SIZE*2, ROW * CELL_SIZE), "Play", Style::Default);
	RectangleShape Cell(Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));
	RectangleShape BackgroundCell(Vector2f(CELL_SIZE - 1, CELL_SIZE -1));

	Block* blocks[] = { new IBlock,new JBlock,new LBlock,new OBlock,new SBlock,new TBlock,new ZBlock };

	World world;
	Draw drawer;
	text textToDisplay;
	SoundPlay soundPlay;


	int blockKind = rand() % 7;
	int currentX = COL/2 -1; //to start from the middle
	int currentY = 0; // to start from the top
	Clock clock;
	int score = 0;
	int level = 1;
	int line = 0;

	float previousTime = clock.getElapsedTime().asSeconds();

	/*soundPlay.playThemeSound();*/
	while (playWindow.isOpen()) {



		//auto movement
		float autoTime = level * ((static_cast<float>(10) - level + 1) / (10 * level));
		if (clock.getElapsedTime().asSeconds() - previousTime >=1) {
			previousTime = clock.getElapsedTime().asSeconds();
			moveDown(blocks, world, currentX, currentY, blockKind, score, line,soundPlay);
		}



		Event event;
		while (playWindow.pollEvent(event)) {
			if (event.type == Event::Closed)
				playWindow.close();
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Left) {
					currentX--;
					soundPlay.playMovementSound();
					if (checkBlock(blocks, world, currentX, currentY, blockKind) == false)
						currentX++;
					break;
				}

				if (event.key.code == Keyboard::Right) {
					currentX++;
					soundPlay.playMovementSound();
					if (checkBlock(blocks, world, currentX, currentY, blockKind) == false)
						currentX--;
					break;
				}

				if (event.key.code == Keyboard::Down) {
					soundPlay.playMovementSound();
					moveDown(blocks, world, currentX, currentY, blockKind, score, line,soundPlay);
					score++;
					break;

				}
				if (event.key.code == Keyboard::Up) {
					soundPlay.playRotationSound();
					blocks[blockKind]->rotate();
					while (rotationCheck(blocks, currentX, blockKind) == false);
					break;

				}
				if (event.key.code == Keyboard::Space) {
					while (moveDown(blocks, world, currentX, currentY, blockKind, score, line,soundPlay) == true) {
						score++;
					}
					break;
				}
				if (event.key.code == Keyboard::Escape)
					playWindow.close();
			}

		}
		if (level < 5) {
			level = score / 500 + 1;


		}
		

		playWindow.clear(Color::Black);

		drawer.drawBackGroundWorld(playWindow, BackgroundCell);
		drawer.drawWorld(playWindow, Cell, world);
		drawer.drawBlock(playWindow, Cell, blocks, blockKind, currentX, currentY);

		textToDisplay.setText(name, score, level, line);
		textToDisplay.drawText(playWindow);
		if (world.endGameCheck()) {
			playWindow.close();
			highscore.newScore(to_string(score),name);
		}
		playWindow.display();
	}
	
}


void highScore(Highscore& highscore,const string& name) {
	RenderWindow highscoreWindow(VideoMode(CELL_SIZE * COL * 2, CELL_SIZE * ROW), "Highscore", Style::Default);
	RectangleShape background;
	background.setSize(Vector2f(CELL_SIZE * COL * 2, CELL_SIZE * ROW));
	Texture backgroundImage;
	backgroundImage.loadFromFile("backgrounds/background.jpg");
	background.setTexture(&backgroundImage);



	while (highscoreWindow.isOpen()) {
		Event event;
		while (highscoreWindow.pollEvent(event)) {
			if (event.type == Event::Closed)
				highscoreWindow.close();
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Escape)
					highscoreWindow.close();
			}
		}
		highscoreWindow.clear();
		highscoreWindow.draw(background);
		highscore.drawScore(highscoreWindow);
		highscoreWindow.display();

	}




}

int main() {
	RenderWindow menuWindow(VideoMode(CELL_SIZE * COL * 2, CELL_SIZE * ROW ),"Tetris",Style::Default);
	RectangleShape background;
	background.setSize(Vector2f(CELL_SIZE * COL * 2, CELL_SIZE * ROW));
	Texture backgroundImage;
	backgroundImage.loadFromFile("backgrounds/background.jpg");
	background.setTexture(&backgroundImage);

	Highscore highscore;


	Menu menu;
	string name = "";
	while (menuWindow.isOpen()) {
		Event menuEvent;
		while (menuWindow.pollEvent(menuEvent)) {
			if (menuEvent.type == Event::Closed) {
				menuWindow.close();
			}
			if (menuEvent.type == Event::KeyPressed) {
				if (menuEvent.key.code == Keyboard::Up) {
					menu.moveUp();

				}
				if (menuEvent.key.code == Keyboard::Down) {
					menu.moveDown();
				}
				if (menuEvent.key.code == Keyboard::Escape) {
					menuWindow.close();
				}
				if (menuEvent.key.code == Keyboard::Return) {
					int x = menu.selectedOption();
					if (x == 0) {
						
						cout << "Enter your name: ";
						getline(cin, name);
						play(highscore,name);
					}
					else if (x == 1) {
						highScore(highscore,name);
					}
					else if (x == 2)
						menuWindow.close();

				}
			}
		}
		menuWindow.clear();
		menuWindow.draw(background);
		menu.draw(menuWindow);
		menuWindow.display();
	}


}



