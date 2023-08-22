#pragma once
#include<iostream>

using namespace std;
class Block {

public:
	 virtual void rotate()= 0;
	 virtual int getValueAtIndex(int i, int j)= 0 ;
	 virtual void setValueAtIndex(int i,int j,int value) = 0;
};



class IBlock:public Block {
private:
	int arr[4][4] = { 1,0,0,0,
					  1,0,0,0,
					  1,0,0,0,
					  1,0,0,0};

public:
	void rotate() {
		int blockLength = 4;
		//rotating counter clock-wise by 90 degree
		int temp[4][4] = { 0 };
		for (int i = 0; i < blockLength; i++) {
			for (int j = 0; j < blockLength; j++) {
				if (this->arr[i][j])
					temp[j][blockLength - 1 - i] = 1;
			}
		}


		//coping in original block
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				this->arr[i][j] = temp[i][j];
			}
		}
	}

	int getValueAtIndex(int i, int j) {
		if (i < 4 && j < 4)
			return this->arr[i][j];
	}

	void setValueAtIndex(int i,int j,int value) {
		if (i < 4 && j < 4)
			this->arr[i][j] = value;
	}

};

class JBlock :public Block {
private:
	int arr[4][4] = { 0,1,0,0,
					  0,1,0,0,
					  1,1,0,0,
					  0,0,0,0 };

public:
	void rotate() {
		int blockLength = 3;

		//rotating counter clock-wise by 90 degree
		int temp[4][4] = { 0 };
		for (int i = 0; i < blockLength; i++) {
			for (int j = 0; j < blockLength; j++) {
				if (this->arr[i][j])
					temp[j][blockLength - 1 - i] = 1;
			}
		}

		//coping in original block
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				this->arr[i][j] = temp[i][j];
			}
		}
	}


	int getValueAtIndex(int i, int j) {
		if (i < 4 && j < 4)
			return this->arr[i][j];
	}
	void setValueAtIndex(int i, int j, int value) {
		if (i < 4 && j < 4)
			this->arr[i][j] = value;
	}



};
class LBlock :public Block {
private:
	int arr[4][4] = { 1,0,0,0,
					  1,0,0,0,
					  1,1,0,0,
					  0,0,0,0 };
public:
	void rotate() {
		int blockLength = 3;

		//rotating counter clock-wise by 90 degree
		int temp[4][4] = { 0 };
		for (int i = 0; i < blockLength; i++) {
			for (int j = 0; j < blockLength; j++) {
				if (this->arr[i][j])
					temp[j][blockLength - 1 - i] = 1;
			}
		}

		//coping in original block
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				this->arr[i][j] = temp[i][j];
			}
		}
	}
	int getValueAtIndex(int i, int j) {
		if (i < 4 && j < 4)
			return this->arr[i][j];
	}
	void setValueAtIndex(int i, int j, int value) {
		if (i < 4 && j < 4)
			this->arr[i][j] = value;
	}


};
class OBlock :public Block {
private:
	int arr[4][4] = { 1,1,0,0,
					  1,1,0,0,
					  0,0,0,0,
					  0,0,0,0 };
public:
	void rotate() {

	}
	int getValueAtIndex(int i, int j) {
		if (i < 4 && j < 4)
			return this->arr[i][j];
	}
	void setValueAtIndex(int i, int j, int value) {
		if (i < 4 && j < 4)
			this->arr[i][j] = value;
	}
};
class SBlock :public Block {
private:
	int arr[4][4] = { 1,0,0,0,
					  1,1,0,0,
					  0,1,0,0,
					  0,0,0,0 };
public:
	void rotate() {
		int blockLength = 3;

		//rotating counter clock-wise by 90 degree
		int temp[4][4] = { 0 };
		for (int i = 0; i < blockLength; i++) {
			for (int j = 0; j < blockLength; j++) {
				if (this->arr[i][j])
					temp[j][blockLength - 1 - i] = 1;
			}
		}

		//coping in original block
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				this->arr[i][j] = temp[i][j];
			}
		}
	}
	int getValueAtIndex(int i, int j) {
		if (i < 4 && j < 4)
			return this->arr[i][j];
	}
	void setValueAtIndex(int i, int j, int value) {
		if (i < 4 && j < 4)
			this->arr[i][j] = value;
	}
};
class TBlock :public Block {
private:
	int arr[4][4] = { 1,0,0,0,
					  1,1,0,0,
					  1,0,0,0,
					  0,0,0,0 };
public:
	void rotate() {
		int blockLength = 3;


		//rotating counter clock-wise by 90 degree
		int temp[4][4] = { 0 };
		for (int i = 0; i < blockLength; i++) {
			for (int j = 0; j < blockLength; j++) {
				if (this->arr[i][j])
					temp[j][blockLength -1-i] = 1;
			}
		}

		//coping in original block
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				this->arr[i][j] = temp[i][j];
			}
		}
	}
	int getValueAtIndex(int i, int j) {
		if (i < 4 && j < 4)
			return this->arr[i][j];
	}
	void setValueAtIndex(int i, int j, int value) {
		if (i < 4 && j < 4)
			this->arr[i][j] = value;
	}
};

class ZBlock :public Block {
private:
	int arr[4][4] = { 0,1,0,0,
					  1,1,0,0,
					  1,0,0,0,
					  0,0,0,0 };
public:
	void rotate() {
		int blockLength = 3;

		//rotating  clock-wise by 90 degree
		int temp[4][4] = { 0 };
		for (int i = 0; i < blockLength; i++) {
			for (int j = 0; j < blockLength; j++) {
				if (this->arr[i][j])
					temp[j][blockLength-1- i] = 1;
			}
		}

		//coping in original block
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				this->arr[i][j] = temp[i][j];
			}
		}
	}
	int getValueAtIndex(int i, int j) {
		if (i < 4 && j < 4)
			return this->arr[i][j];
	}
	void setValueAtIndex(int i, int j, int value) {
		if (i < 4 && j < 4)
			this->arr[i][j] = value;
	}

};



