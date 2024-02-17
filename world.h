#pragma once
#include"myvector.hpp"

class World {
private:
    MyVector<MyVector<int>> mArr;
public:
    World(const int rows ,const int columns);
    ~World();
    void setValueAtIndex(const int i,const int j, const int value);
    int getValueAtIndex(const int i,const  int j);
    void clearLines(int& score, int& line,const int rows,const int columns);
    bool endGameCheck(const int columns);
};
