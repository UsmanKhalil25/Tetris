// Menu.cpp
#include<iostream>
#include "Menu.h"

Menu::Menu(float resX,float resY):mCurrentOption(0),mThemeCurrentOption(0),mDifficultyCurrentOption(0), menuState(MenuState::Main) {
    
    mTexture.loadFromFile("backgrounds/background1.jpg");
    mBackground.setTexture(&mTexture);
    mBackground.setSize(sf::Vector2f(resX, resY));

    if (!mFont.loadFromFile("fonts/norwester.otf"))
        std::cout << "Font not loaded\n";

    mMainMenuOptions[0].setString("New Game");
    mMainMenuOptions[1].setString("Difficulty Settings");
    mMainMenuOptions[2].setString("Scores");
    mMainMenuOptions[3].setString("Theme Selection");
    mMainMenuOptions[4].setString("Exit");

    for (int i = 0; i < numberOfMainMenuOptions; i++) {
        mMainMenuOptions[i].setFont(mFont);
        mMainMenuOptions[i].setFillColor(sf::Color::White);
        mMainMenuOptions[i].setOutlineColor(sf::Color(255, 16, 240));
        mMainMenuOptions[i].setOutlineThickness(2);
        mMainMenuOptions[i].setCharacterSize(50);
       mMainMenuOptions[i].setPosition(resX / 2 - mMainMenuOptions[i].getString().getSize() * 10, resY / 8 + i * resY / 10);
    }

    mThemeChangeOptions[0].setString("Current Theme: Dark");
    mThemeChangeOptions[1].setString("Dark Theme");
    mThemeChangeOptions[2].setString("Light Theme");
    for (int i = 0; i < numberOfThemeChangeOptions; i++) {
        mThemeChangeOptions[i].setFont(mFont);
        mThemeChangeOptions[i].setFillColor(sf::Color::White);
        mThemeChangeOptions[i].setOutlineColor(sf::Color(255, 16, 240));
        mThemeChangeOptions[i].setOutlineThickness(2);
        mThemeChangeOptions[i].setCharacterSize(50);
        mThemeChangeOptions[i].setPosition(resX / 2 - mThemeChangeOptions[i].getString().getSize() * 10, resY / 8 + i * resY / 10);
    }

    mDifficultySettingsOptions[0].setString("Current Difficulty: Easy");
    mDifficultySettingsOptions[1].setString("Easy");
    mDifficultySettingsOptions[2].setString("Medium");
    mDifficultySettingsOptions[3].setString("Hard");

    for (int i = 0; i < numberOfDifficultyOptions; i++) {
        mDifficultySettingsOptions[i].setFont(mFont);
        mDifficultySettingsOptions[i].setFillColor(sf::Color::White);
        mDifficultySettingsOptions[i].setOutlineColor(sf::Color(255, 16, 240));
        mDifficultySettingsOptions[i].setOutlineThickness(2);
        mDifficultySettingsOptions[i].setCharacterSize(50);
        mDifficultySettingsOptions[i].setPosition(resX / 2 - mDifficultySettingsOptions[i].getString().getSize() * 10, resY / 8 + i * resY / 10);
    }
   

}


void Menu::moveUp() {
    if (menuState == MenuState::Main) {
        if (mCurrentOption - 1 >= 0) {
            mMainMenuOptions[mCurrentOption].setFillColor(sf::Color::White);
            mMainMenuOptions[mCurrentOption].setOutlineColor(sf::Color(255, 16, 240));

            mCurrentOption--;
            if (mCurrentOption <= -1)
                mCurrentOption = numberOfMainMenuOptions - 1;
            mMainMenuOptions[mCurrentOption].setFillColor(sf::Color(255, 16, 240));
            mMainMenuOptions[mCurrentOption].setOutlineColor(sf::Color::White);
        }
    }
    else if (menuState == MenuState::ThemeSelection) {
        if (mThemeCurrentOption - 1 >= 0) {
            mThemeChangeOptions[mThemeCurrentOption].setFillColor(sf::Color::White);
            mThemeChangeOptions[mThemeCurrentOption].setOutlineColor(sf::Color(255, 16, 240));

            mThemeCurrentOption--;
            if (mThemeCurrentOption <= 0)
                mThemeCurrentOption = 2;
            mThemeChangeOptions[mThemeCurrentOption].setFillColor(sf::Color(255, 16, 240));
            mThemeChangeOptions[mThemeCurrentOption].setOutlineColor(sf::Color::White);
        }
    }
    else if (menuState == MenuState::DifficultySettings) {
        if (mDifficultyCurrentOption - 1 >= 0) {
            mDifficultySettingsOptions[mDifficultyCurrentOption].setFillColor(sf::Color::White);
            mDifficultySettingsOptions[mDifficultyCurrentOption].setOutlineColor(sf::Color(255, 16, 240));

            mDifficultyCurrentOption--;
            if (mDifficultyCurrentOption <= 0)
                mDifficultyCurrentOption = 3;
            mDifficultySettingsOptions[mDifficultyCurrentOption].setFillColor(sf::Color(255, 16, 240));
            mDifficultySettingsOptions[mDifficultyCurrentOption].setOutlineColor(sf::Color::White);
        }
    }
    
}

void Menu::moveDown() {
    if (menuState == MenuState::Main) {
        if (mCurrentOption + 1 <= numberOfMainMenuOptions) {
            mMainMenuOptions[mCurrentOption].setFillColor(sf::Color::White);
            mMainMenuOptions[mCurrentOption].setOutlineColor(sf::Color(255, 16, 240));

            mCurrentOption++;

            if (mCurrentOption >= numberOfMainMenuOptions)
                mCurrentOption = 0;
            mMainMenuOptions[mCurrentOption].setFillColor(sf::Color(255, 16, 240));
            mMainMenuOptions[mCurrentOption].setOutlineColor(sf::Color::White);
        }
    }
    else if (menuState == MenuState::ThemeSelection) {
        if (mThemeCurrentOption +1 <= numberOfThemeChangeOptions) {
            mThemeChangeOptions[mThemeCurrentOption].setFillColor(sf::Color::White);
            mThemeChangeOptions[mThemeCurrentOption].setOutlineColor(sf::Color(255, 16, 240));

            mThemeCurrentOption++;
            if (mThemeCurrentOption >= 3)
                mThemeCurrentOption = 1;
            mThemeChangeOptions[mThemeCurrentOption].setFillColor(sf::Color(255, 16, 240));
            mThemeChangeOptions[mThemeCurrentOption].setOutlineColor(sf::Color::White);
        }
    }
    else if (menuState == MenuState::DifficultySettings) {
        if (mDifficultyCurrentOption + 1 <= numberOfDifficultyOptions) {
            mDifficultySettingsOptions[mDifficultyCurrentOption].setFillColor(sf::Color::White);
            mDifficultySettingsOptions[mDifficultyCurrentOption].setOutlineColor(sf::Color(255, 16, 240));

            mDifficultyCurrentOption++;
            if (mDifficultyCurrentOption >= 4)
                mDifficultyCurrentOption = 1;
            mDifficultySettingsOptions[mDifficultyCurrentOption].setFillColor(sf::Color(255, 16, 240));
            mDifficultySettingsOptions[mDifficultyCurrentOption].setOutlineColor(sf::Color::White);
        }
    }
}

void Menu::handleEvent(sf::Event event, MainState& mainState,int& score,std::string& name,bool& theme,int& difficulty){

    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            moveUp();

        }
        if (event.key.code ==sf::Keyboard::Down) {
            moveDown();
        }
        if (event.key.code == sf::Keyboard::Escape) {
            if (menuState == MenuState::Main) 
                mainState = MainState::Exit;
            else if (menuState == MenuState::DifficultySettings || menuState == MenuState::ScoreBoard || menuState == MenuState::ThemeSelection)
                menuState = MenuState::Main;
        }
        if (event.key.code == sf::Keyboard::Return) {
            if (menuState == MenuState::Main) {
                int x = selectedOption();
                if (x == 0) {
                    std::cout << "Enter your name: ";
                    std::getline(std::cin, name);
                    mainState = MainState::Game;
                }
                else if (x == 1) {
                    menuState = MenuState::DifficultySettings;
                }
                else if (x == 2) {
                    menuState = MenuState::ScoreBoard;
                }
                else if (x == 3) {
                    menuState = MenuState::ThemeSelection;
                }
                else if (x == 4) {
                    mainState = MainState::Exit;
                }
            }
            else if (menuState == MenuState::ThemeSelection) {
                int x = mThemeCurrentOption;
                if (x == 1)
                    theme = false;
                else if (x == 2)
                    theme = true;
            }
            else if (menuState == MenuState::DifficultySettings) {
                int x = mDifficultyCurrentOption;
                difficulty = x;
                
            }
            
        }
    }
}


void Menu::update(MainState& mainState, int& score, std::string& name,bool& theme,int& difficulty){
    if (menuState == MenuState::Main) {

    }
    else if (menuState == MenuState::DifficultySettings) {
        std::string temp = "Current Difficulty: ";
        if (difficulty == 1)
            temp += "Easy";
        else if (difficulty == 2)
            temp += "Medium";
        else if (difficulty)
            temp += "Hard";
        mDifficultySettingsOptions[0].setString(temp);
    }
    else if (menuState == MenuState::ScoreBoard) {
        
    }
    else if (menuState == MenuState::ThemeSelection) {
        std::string temp = "Current Theme: ";
        if (theme)
            temp += "Light";
        else
            temp += "Dark";
        mThemeChangeOptions[0].setString(temp);
    }
}

void Menu::draw(sf::RenderWindow& window, MainState& mainState, int& score, std::string& name,Highscore& highscore) {
    window.draw(mBackground);
    if (menuState == MenuState::Main) {
        for (int i = 0; i < numberOfMainMenuOptions; i++)
            window.draw(this->mMainMenuOptions[i]);
    }
    else if (menuState == MenuState::ScoreBoard) {
        highscore.drawScore(window);
    }
    else if (menuState == MenuState::ThemeSelection) {
        for (int i = 0; i < numberOfThemeChangeOptions; i++)
            window.draw(this->mThemeChangeOptions[i]);
    }
    else if (menuState == MenuState::DifficultySettings) {
        for (int i = 0; i < numberOfDifficultyOptions; i++)
            window.draw(this->mDifficultySettingsOptions[i]);
    }
}

int Menu::selectedOption() {
    return mCurrentOption;
}
