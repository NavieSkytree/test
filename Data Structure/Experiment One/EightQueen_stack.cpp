#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
struct rcInfo{
  rcInfo(int i,int j):row(i),col(j){};
  int row;
  int col;
};
stack<rcInfo> chessStack;
bool check(int chess[8][8],int row,int col) {
	//check vertical and horiontal
  // int row=tmp.row;
  // int col=tmp.col;
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
void EQueen(int chess[8][8]) {
  int tmp;
  for(int i=0;i<8;i++){
    tmp=i;
    while (1) {
      for(int j=0;j<8;++j){
        if(check(chess,tmp,j)){
          chess[tmp][j]=1;
          chessStack.emplace(tmp,j);
          tmp++;
          print(chess);
          break;
        }
        if(7==j){
          rcInfo &data=chessStack.top();
          chessStack.pop();
          chess[data.row][data.col]=0;
          tmp=data.row;
          j=data.col;
          continue;
        }
      }

      if(8==tmp){
        print(chess);
      }
    }
  }
}
int main(int argc, char const *argv[]) {
	// int chessboard[8][8] = { 0 };
	// EQueen(chessboard);

	return 0;
}
