#include<iostream>
using namespace std;
bool check(int chess[8][8], int row, int col) {
	//check vertical and horiontal
	for (int i = 0;i < 8;++i) {
		if (chess[row][i] == 1)
			return false;
	}
	for (int i = 0;i < 8;++i) {
		if (chess[i][col] == 1)
			return false;
	}
	//check diagonal
	int tmp_row = row, tmp_col = col;
	while (tmp_row >= 0 && tmp_col >= 0) {
		if (chess[tmp_row--][tmp_col--] == 1)return false;
	}
	tmp_row = row, tmp_col = col;
	while (tmp_row<8 && tmp_col<8) {
		if (chess[tmp_row++][tmp_col++] == 1)return false;
	}
	tmp_row = row, tmp_col = col;
	while (tmp_row >= 0 && tmp_col<8) {
		if (chess[tmp_row--][tmp_col++] == 1)return false;
	}
	tmp_row = row, tmp_col = col;
	while (tmp_row<8 && tmp_col >= 0) {
		if (chess[tmp_row++][tmp_col--] == 1)return false;
	}
	return true;
}
void print(int chess[8][8]) {
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0;j < 8;j++) {
			cout << chess[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}
void EQueen(int chess[8][8], int row) {
	if (8 == row) {
		static int total = 0;
		total++;
		cout << total << endl;
		print(chess);
	}
	else {
		for (int i=0;i <8; i++) {
			for(int j = 0;j < 8;j++) chess[row][j] = 0;//回溯时清空标记非常重要
			if (check(chess, row, i)) {
				chess[row][i] = 1;
				print(chess);
				EQueen(chess, row + 1);
			}
		}
	}
}
int main(int argc, char const *argv[]) {
	int chessboard[8][8] = { 0 };
	print(chessboard);
	EQueen(chessboard, 0);

	system("pause");
	return 0;
}
