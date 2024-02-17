#pragma once

#include"myvector.hpp"

using namespace std;
class Block {

public:
	virtual void rotate() = 0;
	virtual int getValueAtIndex(int i, int j) = 0;
	virtual void setValueAtIndex(int i, int j, int value) = 0;
	virtual int getValueAtIndexOriginal(int i, int j) = 0;
};


class IBlock : public Block {
private:
	MyVector<MyVector<int>> mOriginal = 
		{{1,0,0,0},
		{1,0,0,0},
		{1,0,0,0},
		{1,0,0,0 }};
	MyVector<MyVector<int>> mArr =
	{ {1,0,0,0},
	{1,0,0,0},
	{1,0,0,0},
	{1,0,0,0 } };

public:
	void rotate();
	int getValueAtIndex(int i, int j);
	void setValueAtIndex(int i, int j, int value);
	int getValueAtIndexOriginal(int i, int j);
};




class JBlock :public Block {
private:

	MyVector<MyVector<int>> mOriginal =
	{{0,1,0,0},
	{0,1,0,0},
	{1,1,0,0},
	{0,0,0,0 } };
	MyVector<MyVector<int>> mArr =
	{ {0,1,0,0},
	{0,1,0,0},
	{1,1,0,0},
	{0,0,0,0 } };

public:
	void rotate();
	int getValueAtIndex(int i, int j);
	void setValueAtIndex(int i, int j, int value);
	int getValueAtIndexOriginal(int i, int j);


};
class LBlock :public Block {
private:
	MyVector<MyVector<int>> mOriginal =
	{ {1,0,0,0},
	{1,0,0,0},
	{1,1,0,0},
	{0,0,0,0 } };
	MyVector<MyVector<int>> mArr =
	{ {1,0,0,0},
	{1,0,0,0},
	{1,1,0,0},
	{0,0,0,0 } };
	
public:
	void rotate();
	int getValueAtIndex(int i, int j);
	void setValueAtIndex(int i, int j, int value);
	int getValueAtIndexOriginal(int i, int j);
};
class OBlock :public Block {
private:

	MyVector<MyVector<int>> mOriginal = 
	{ {1,1,0,0},
	{1,1,0,0},
	{0,0,0,0},
	{0,0,0,0 } };
	MyVector<MyVector<int>> mArr =
	{ {1,1,0,0},
	{1,1,0,0},
	{0,0,0,0},
	{0,0,0,0 } };
public:
	void rotate();
	int getValueAtIndex(int i, int j);
	void setValueAtIndex(int i, int j, int value);
	int getValueAtIndexOriginal(int i, int j);
};
class SBlock :public Block {
private:

	MyVector<MyVector<int>> mOriginal =
	{ {1,0,0,0},
	{1,1,0,0},
	{0,1,0,0},
	{0,0,0,0 } };
	MyVector<MyVector<int>> mArr =
	{ {1,0,0,0},
	{1,1,0,0},
	{0,1,0,0},
	{0,0,0,0 } };
public:
	void rotate();
	int getValueAtIndex(int i, int j);
	void setValueAtIndex(int i, int j, int value);
	int getValueAtIndexOriginal(int i, int j);
};
class TBlock :public Block {
private:

	MyVector<MyVector<int>> mOriginal =
	{ {1,0,0,0},
	{1,1,0,0},
	{1,0,0,0},
	{0,0,0,0 } };
	MyVector<MyVector<int>> mArr =
	{ {1,0,0,0},
	{1,1,0,0},
	{1,0,0,0},
	{0,0,0,0 } };
public:
	void rotate();
	int getValueAtIndex(int i, int j);
	void setValueAtIndex(int i, int j, int value);
	int getValueAtIndexOriginal(int i, int j);
};

class ZBlock :public Block {
private:

	MyVector<MyVector<int>> mOriginal = 
	{ {0,1,0,0},
	{1,1,0,0},
	{1,0,0,0},
	{0,0,0,0 } };
	MyVector<MyVector<int>> mArr =
	{ {0,1,0,0},
	{1,1,0,0},
	{1,0,0,0},
	{0,0,0,0 } };
public:
	void rotate();
	int getValueAtIndex(int i, int j);
	void setValueAtIndex(int i, int j, int value);
	int getValueAtIndexOriginal(int i, int j);

};


