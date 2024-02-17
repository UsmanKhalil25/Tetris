#include<SFML/Graphics.hpp>
#include <random>

#include"state.h"
#include"tetrimino.h"
#include"world.h"
#include"text.h"
#include"menu.h"
#include"score.h"

enum class GameState {
	Play,
	Pause
};

class Game {
private:

	int mCellSize;
	int mRows;
	int mCols;
	int mResolutionX;
	int mResolutionY;
	int mCheckScore;

	sf::RectangleShape mCell;
	sf::RectangleShape mBackgroundCell;
	sf::Clock mClock;
	sf::Color mClearColor;
	sf::Color mTextColor;
	sf::Color mCellColor;
	
	int mNumberOfBlocks;
	Block* mBlocks[7] = { new IBlock,new JBlock,new LBlock,new OBlock,new SBlock,new TBlock,new ZBlock };
	sf::Color mColors[7] = { sf::Color::Cyan,sf::Color::Blue,sf::Color(255,165,0),sf::Color::Yellow,sf::Color::Green,sf::Color(128,0,128),sf::Color::Red };

	World mWorld;
	CustomText mText;

	

	int mBlockKind;
	int mNextBlockKind;
	int mHoldBlockKind;

	int mCurrentX;
	int mCurrentY;
	int mScore;
	int mLevel;
	int mLine;
	float mPreviousTime;


public:
	Game(float resX,float resY);
	~Game();

	void handleEvent(sf::Event event, MainState& mainState,int& score,std::string& name,Highscore& highscore);
	void update(MainState& mainState,int& score,std::string& name,int& difficulty,Highscore& highscore);
	void draw(sf::RenderWindow& window, MainState& mainState,bool theme,int& score,std::string& name);

	void drawWorld(sf::RenderWindow& window);
	void drawBlock(sf::RenderWindow& window);
	void drawBackGroundWorld(sf::RenderWindow& window);
	void drawNextBlockPreview(sf::RenderWindow& window);
	void drawHoldBlockPreview(sf::RenderWindow& window);

	bool moveDown();
	bool checkBlock();
	void newBlock();
	bool rotationCheck();
	
};