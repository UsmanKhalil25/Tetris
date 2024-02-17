#include"tetrimino.h"


void IBlock::rotate(){
	int blockLength = 4;
	//rotating counter clock-wise by 90 degree
	int temp[4][4] = { 0 };
	for (int i = 0; i < blockLength; i++) {
		for (int j = 0; j < blockLength; j++) {
			if (this->mArr[i][j])
				temp[j][blockLength - 1 - i] = 1;
		}
	}
	//coping in original block
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			this->mArr[i][j] = temp[i][j];
		}
	}
}

int IBlock::getValueAtIndex(int i, int j){
	if (i < 4 && j < 4)
		return this->mArr[i][j];
}

void IBlock::setValueAtIndex(int i, int j, int value){
	if (i < 4 && j < 4)
		this->mArr[i][j] = value;
}

int IBlock::getValueAtIndexOriginal(int i, int j){
	if (i < 4 && j < 4)
		return this->mOriginal[i][j];
}


void JBlock::rotate(){
	int blockLength = 3;

	//rotating counter clock-wise by 90 degree
	int temp[4][4] = { 0 };
	for (int i = 0; i < blockLength; i++) {
		for (int j = 0; j < blockLength; j++) {
			if (this->mArr[i][j])
				temp[j][blockLength - 1 - i] = 1;
		}
	}

	//coping in original block
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			this->mArr[i][j] = temp[i][j];
		}
	}
}

int JBlock::getValueAtIndex(int i, int j){
	if (i < 4 && j < 4)
		return this->mArr[i][j];
}

void JBlock::setValueAtIndex(int i, int j, int value){
	if (i < 4 && j < 4)
		this->mArr[i][j] = value;
}

int JBlock::getValueAtIndexOriginal(int i, int j) {
	if (i < 4 && j < 4)
		return this->mOriginal[i][j];
}


void LBlock::rotate(){
	int blockLength = 3;

	//rotating counter clock-wise by 90 degree
	int temp[4][4] = { 0 };
	for (int i = 0; i < blockLength; i++) {
		for (int j = 0; j < blockLength; j++) {
			if (this->mArr[i][j])
				temp[j][blockLength - 1 - i] = 1;
		}
	}

	//coping in original block
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			this->mArr[i][j] = temp[i][j];
		}
	}
}

int LBlock::getValueAtIndex(int i, int j){
	if (i < 4 && j < 4)
		return this->mArr[i][j];
}

void LBlock::setValueAtIndex(int i, int j, int value){
	if (i < 4 && j < 4)
		this->mArr[i][j] = value;
}
int LBlock::getValueAtIndexOriginal(int i, int j) {
	if (i < 4 && j < 4)
		return this->mOriginal[i][j];
}

void OBlock::rotate(){}

int OBlock::getValueAtIndex(int i, int j){
	if (i < 4 && j < 4)
		return this->mArr[i][j];
}

void OBlock::setValueAtIndex(int i, int j, int value){
	if (i < 4 && j < 4)
		this->mArr[i][j] = value;
}
int OBlock::getValueAtIndexOriginal(int i, int j) {
	if (i < 4 && j < 4)
		return this->mOriginal[i][j];
}

void SBlock::rotate(){
	int blockLength = 3;

	//rotating counter clock-wise by 90 degree
	int temp[4][4] = { 0 };
	for (int i = 0; i < blockLength; i++) {
		for (int j = 0; j < blockLength; j++) {
			if (this->mArr[i][j])
				temp[j][blockLength - 1 - i] = 1;
		}
	}

	//coping in original block
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			this->mArr[i][j] = temp[i][j];
		}
	}
}

int SBlock::getValueAtIndex(int i, int j){
	if (i < 4 && j < 4)
		return this->mArr[i][j];
}

void SBlock::setValueAtIndex(int i, int j, int value){
	if (i < 4 && j < 4)
		this->mArr[i][j] = value;
}
int SBlock::getValueAtIndexOriginal(int i, int j) {
	if (i < 4 && j < 4)
		return this->mOriginal[i][j];
}

void TBlock::rotate(){
	int blockLength = 3;


	//rotating counter clock-wise by 90 degree
	int temp[4][4] = { 0 };
	for (int i = 0; i < blockLength; i++) {
		for (int j = 0; j < blockLength; j++) {
			if (this->mArr[i][j])
				temp[j][blockLength - 1 - i] = 1;
		}
	}

	//coping in original block
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			this->mArr[i][j] = temp[i][j];
		}
	}
}

int TBlock::getValueAtIndex(int i, int j){
	if (i < 4 && j < 4)
		return this->mArr[i][j];
}

void TBlock::setValueAtIndex(int i, int j, int value) {
	if (i < 4 && j < 4)
		this->mArr[i][j] = value;
}
int TBlock::getValueAtIndexOriginal(int i, int j) {
	if (i < 4 && j < 4)
		return this->mOriginal[i][j];
}

void ZBlock::rotate(){
	int blockLength = 3;

	//rotating  clock-wise by 90 degree
	int temp[4][4] = { 0 };
	for (int i = 0; i < blockLength; i++) {
		for (int j = 0; j < blockLength; j++) {
			if (this->mArr[i][j])
				temp[j][blockLength - 1 - i] = 1;
		}
	}

	//coping in original block
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			this->mArr[i][j] = temp[i][j];
		}
	}
}

int ZBlock::getValueAtIndex(int i, int j) {
	if (i < 4 && j < 4)
		return this->mArr[i][j];
}

void ZBlock::setValueAtIndex(int i, int j, int value) {
	if (i < 4 && j < 4)
		this->mArr[i][j] = value;
}
int ZBlock::getValueAtIndexOriginal(int i, int j) {
	if (i < 4 && j < 4)
		return this->mOriginal[i][j];
}