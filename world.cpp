#include "World.h"

World::World(const int rows, const int columns) :mArr(rows,MyVector(columns,0)) {}

World::~World() {}


void World::setValueAtIndex(const int i,const int j,const int value) {
    this->mArr[i][j] = value;
}

int World::getValueAtIndex(const int i,const int j) {
    return this->mArr[i][j];
}

void World::clearLines(int& score, int& line,const int rows,const int columns) {
    int bottomLine = rows - 1;

    for (int i = rows - 1; i >= 0; i--) {
        int count = 0;
        for (int j = 0; j < columns; j++) {
            if (this->mArr[i][j])
                count++;
        }
        if (count < columns) {
            for (int j = 0; j < columns; j++)
                this->mArr[bottomLine][j] = this->mArr[i][j];
            bottomLine--;
        }
        else {
            score += 100;
            line++;
        }
    }
}


bool World::endGameCheck(const int columns) {
    for (int i = 0; i < columns; i++) {
        if (this->mArr[0][i])
            return true;
    }
    return false;
}

