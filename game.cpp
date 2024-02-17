#include"game.h"



Game::Game(float resX,float resY) : mCellSize(36), mRows(20), mCols(10),mResolutionX(resX),mResolutionY(resY), mCell(sf::Vector2f(mCellSize - 1, mCellSize - 1)), mBackgroundCell(sf::Vector2f(mCellSize - 1, mCellSize - 1)), mNumberOfBlocks(6), mWorld(mRows, mCols), mCurrentX(mCols / 2 - 1),mHoldBlockKind(-1), mCurrentY(0), mScore(0),mCheckScore(0), mLine(0), mLevel(1), mPreviousTime(mClock.getElapsedTime().asSeconds()), mText(mRows, mCols, mCellSize, mResolutionX, mResolutionY) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(0, mNumberOfBlocks-1);
	mNextBlockKind = distrib(gen);
	mBlockKind = 0;

}

Game::~Game() {
	// Delete dynamically allocated Block objects
	for (int i = 0; i < 7; ++i) {
		delete mBlocks[i];
	}
}

void Game::drawBackGroundWorld(sf::RenderWindow& window) {
	mBackgroundCell.setFillColor(mCellColor);
	for (int i = 0; i < mRows; i++) {
		for (int j = 0; j < mCols; j++) {
			mBackgroundCell.setPosition( mResolutionX/3 + mCellSize * j, mCellSize * i);
			window.draw(mBackgroundCell);
		}
	}
}



void Game::drawWorld(sf::RenderWindow& window) {
	for (int i = 0; i < mRows; i++) {
		for (int j = 0; j < mCols; j++) {
			if (mWorld.getValueAtIndex(i, j)) {
				mCell.setFillColor(mColors[mWorld.getValueAtIndex(i, j) - 1]);
				mCell.setPosition(mResolutionX / 3 + j * mCellSize, i * mCellSize);
				window.draw(mCell);
			}
		}
	}
}

void Game::drawBlock(sf::RenderWindow& window) {
	mCell.setFillColor(sf::Color(mColors[mBlockKind]));
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (mBlocks[mBlockKind]->getValueAtIndex(i, j)) {
				mCell.setPosition((mCurrentX + j) * mCellSize + mResolutionX / 3, (mCurrentY + i) * mCellSize);
				window.draw(mCell);
			}
		}
	}
}

void Game::drawNextBlockPreview(sf:: RenderWindow& window) {
	mCell.setFillColor(sf::Color(mColors[mNextBlockKind]));
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (mBlocks[mNextBlockKind]->getValueAtIndexOriginal(i, j)) {
				mCell.setPosition( 175.0f + (j * mCellSize), 210.0f+(i * mCellSize));
				window.draw(mCell);
			}
		}
	}
}
void Game::drawHoldBlockPreview(sf::RenderWindow& window) {
	if (mHoldBlockKind != -1) {
		mCell.setFillColor(sf::Color(mColors[mHoldBlockKind]));
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (mBlocks[mHoldBlockKind]->getValueAtIndexOriginal(i, j)) {
					mCell.setPosition(175.0f + (j * mCellSize), 510.0f + (i * mCellSize));
					window.draw(mCell);
				}
			}
		}
	}
	
}



bool Game::checkBlock() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (mBlocks[mBlockKind]->getValueAtIndex(i, j) == 0)
				continue;
			if (mCurrentX + j < 0 || mCurrentX + j >= mCols || mCurrentY + i >= mRows)//collision with wall and bottom
				return false;
			if (mWorld.getValueAtIndex(mCurrentY + i, mCurrentX + j))//collosion with blocks (world's blocks)
				return false;
		}
	}
	return true;
}

void Game::newBlock() {
	mBlockKind = mNextBlockKind;
	while (mNextBlockKind == mBlockKind) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dist(0, mNumberOfBlocks - 1); // Range of block kinds
		mNextBlockKind = dist(gen); // Use the random generator
	}
	
	mCurrentX = mCols / 2 - 1;
	mCurrentY = 0;
}

bool Game::moveDown() {

	mCurrentY++;
	if (checkBlock() == false)// Block has hit bottom
	{
		mCurrentY--;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (mBlocks[mBlockKind]->getValueAtIndex(i, j)) {
					mWorld.setValueAtIndex(mCurrentY + i, mCurrentX + j, mBlockKind + 1);
				}
			}
		}
		mWorld.clearLines(mScore, mLine,mRows,mCols);
		newBlock();
		return false;
	}
	return true;
}


bool Game::rotationCheck() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (mBlocks[mBlockKind]->getValueAtIndex(i, j) == 0)
				continue;
			if (mCurrentX + j < 0) {
				mCurrentX++;
				return false;
			}

			if (mCurrentX + j >= 10) {
				mCurrentX--;
				return false;
			}
		}
	}
	return true;
}

void Game::handleEvent(sf::Event event, MainState& mainState, int& score, std::string& name,Highscore& highscore){

	if (event.type == sf::Event::Closed)
		mainState = MainState::Exit;
	if (event.type == sf:: Event::KeyPressed) {
		if (event.key.code == sf:: Keyboard::Left) {
			mCurrentX--;
			if (checkBlock() == false)
				mCurrentX++;
		}
		if (event.key.code == sf::Keyboard::Right) {
			mCurrentX++;
			if (checkBlock() == false)
				mCurrentX--;
		}
		if (event.key.code == sf::Keyboard::Down) {
			moveDown();
			mScore++;
		}
		if (event.key.code == sf::Keyboard::Up) {
			mBlocks[mBlockKind]->rotate();
			while (rotationCheck() == false);

		}
		if (event.key.code == sf::Keyboard::Space) {
			while (moveDown() == true) {
				mScore++;
			}
		}
		if (event.key.code == sf::Keyboard::Escape) {
			highscore.newScore(std::to_string(score), name);
			mainState = MainState::Menu;
		}
		if (event.key.code == sf::Keyboard::H) {
			if (mHoldBlockKind == -1) {
				mHoldBlockKind = mBlockKind;
				newBlock();
			}
			else {
				swap(mHoldBlockKind, mBlockKind);
			}

		}
	}
}

void Game::update(MainState& mainState,int& score,std::string& name,int& difficulty,Highscore& highscore) {
	score = mScore;
	float autoTime = difficulty/2 * ((static_cast<float>(10) - difficulty + 1) / (10 * difficulty));
	if (autoTime == 0)
		autoTime = 1;
	if (mClock.getElapsedTime().asSeconds() - mPreviousTime >= autoTime) {
		mPreviousTime = mClock.getElapsedTime().asSeconds();
		moveDown();
	}
	if (mLevel < 5) {
		int temp = mScore / 500 + 1;
		if (mLevel < temp) {
			mLevel = temp;
			mRows--;
		}
		
	}
	if (mWorld.endGameCheck(mCols)) {
		mainState = MainState::Menu;
		highscore.newScore(std::to_string(score), name);
	}
}

void Game::draw(sf::RenderWindow& window, MainState& mainState,bool theme, int& score, std::string& name) {
	if (!theme) {
		// for dark color
		mCellColor = sf::Color(23, 23, 23);
		mClearColor = sf::Color::Black;
		mTextColor = sf::Color(200, 200, 200);

	}
	else {
		// for light color
		mCellColor = sf::Color(190, 190, 190);
		mClearColor = sf::Color::White;
		mTextColor = sf::Color(23, 23, 23);

	}
	window.clear(mClearColor);
	drawBackGroundWorld(window);
	drawWorld(window);
	drawBlock(window);
	drawNextBlockPreview(window);
	drawHoldBlockPreview(window);
	mText.setText( name,mScore, mLevel, mLine,20,mCols,mCellSize,mResolutionX,mResolutionY,mTextColor);
	mText.drawText(window);
}