#include<iostream>
using namespace std;
bool check(int chess[8][8],int row,int col) {
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
	int tmp_row=0, tmp_col=0;
	tmp_row = (row > col) ? 8 : row + (8 - col);
	tmp_col = col + (tmp_row - row);
	while (tmp_row >= 0 && tmp_col >= 0) {
		if (chess[tmp_row][tmp_col]==1)
		{
			return false;
		}
		tmp_row--;
		tmp_col--;
	}

	tmp_row = row;
	tmp_col = col;
	while (tmp_row <7 && tmp_col>1)
	{
		tmp_row++;
		tmp_col--;
	}
	while (tmp_row>=0 && tmp_col<8)
	{
		if (chess[tmp_row][tmp_col] == 1) {
			return false;
		}
		tmp_row--;
		tmp_col++;
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
void EQueen(int chess[8][8]) {
	//for (int k = 0;k < 8;++k) {
		for (int i = 0;i < 8;i++)
		{
			for (int j = 0;j < 8;j++) {
				if (check(chess, i, j)) {
					chess[i][j] = 1;
				}
			}
		}
		print(chess);
	//}
}
int main(int argc, char const *argv[]) {
	int chessboard[8][8];
	for (int i = 0;i < 8;++i)
		for (int j = 0;j < 8;++j)
			chessboard[i][j] = 0;
	print(chessboard);
	EQueen(chessboard);

	system("pause");
	return 0;
}
