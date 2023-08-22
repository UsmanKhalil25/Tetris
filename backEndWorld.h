#pragma once

const int ROW = 20;
const int COL = 10;


class World{
private:
	int arr[ROW][COL] = { 0 };
public:


	void setValueAtIndex(int i, int j, int value) {
		this->arr[i][j] = value;

	}
	int getValueAtIndex(int i, int j) {
		return this->arr[i][j];
	}
	void clearLines(int& score,int &line) {
		int bottomLine = ROW - 1;

		//counting from bottom to top

		for (int i = ROW - 1; i >= 0; i--) {
			int count = 0;
			for (int j = 0; j < COL; j++) {
				if (this->arr[i][j])
					count++;
			}
			if (count < COL) {
				for (int j = 0; j < COL; j++)
					this->arr[bottomLine][j] = this->arr[i][j];
				bottomLine--;
			}
			else{
				score += 100;
				line++;
			}
			

		}
	}
	bool endGameCheck() {
		for (int i = 0; i < COL; i++) {
			if (this->arr[0][i])
				return true;
		}
		return false;
	}



};