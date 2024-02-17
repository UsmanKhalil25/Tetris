#pragma once

#include<iostream>
#include<string>
#include <SFML/Graphics.hpp>
#include<memory>
//including classes
#include"state.h"
#include"score.h"
// number of items in menu
#define numberOfMainMenuOptions 5
#define numberOfThemeChangeOptions 3
#define numberOfDifficultyOptions 4


enum class MenuState {
    Main,
    DifficultySettings,
    ScoreBoard,
    ThemeSelection
};

class Menu {
private:
    int mCurrentOption;
    int mThemeCurrentOption;
    int mDifficultyCurrentOption;

    sf::Font mFont;

    sf::Text mMainMenuOptions[numberOfMainMenuOptions];
    sf::Text mThemeChangeOptions[numberOfThemeChangeOptions];
    sf::Text mDifficultySettingsOptions[numberOfDifficultyOptions];

    sf::RectangleShape mBackground;
    sf::Texture mTexture;

    MenuState menuState;

public:
    Menu(float resX,float resY);
    void moveUp();
    void moveDown();
    void handleEvent(sf::Event event, MainState& mainState, int& score, std::string& name,bool& theme,int& difficulty);
    void update(MainState& mainState,int& score,std::string& name,bool& theme,int& difficulty);
    void draw(sf::RenderWindow& window, MainState& mainState, int& score, std::string& name,Highscore& highscore);
    int selectedOption();
};
