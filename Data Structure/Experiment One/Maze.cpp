#include<iostream>
#include<stack>
#include<random>
using namespace std;
static int maze[10][10] = { 1,1,1,1,1,1,1,1,1,1,
														1,0,0,1,0,0,0,1,0,1,
														1,0,0,1,0,0,0,1,0,1,
														1,0,0,0,0,1,1,0,0,1,
														1,0,1,1,1,0,0,0,0,1,
														1,0,0,0,1,0,0,0,0,1,
														1,0,1,0,0,0,1,0,0,1,
														1,0,1,1,1,0,1,1,0,1,
														1,1,0,0,0,0,0,0,0,0,
														1,1,1,1,1,1,1,1,1,1 };
struct Cordinate {
	Cordinate(int i, int j) :row(i), col(j) {};
	int row;
	int col;
};
bool check(int i, int j) {
	// if (maze[i + 1][j] == 0)return true;
	// if (maze[i][j + 1] == 0)return true;
	// if (maze[i - 1][j] == 0)return true;
	// if (maze[i][j - 1] == 0)return true;
	if(maze[i][j]==0)return true;
	return false;
}
void print() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << maze[i][j] << "  ";
		}
		cout << endl;
	}
}
int main(int argc, char const *argv[]) {
	stack<Cordinate> routr;
	routr.push(Cordinate(1, 8));
	default_random_engine generator;
	uniform_int_distribution<int> distribution(0, 3);
	int tmp_row, tmp_col, rnd;
	while (1) {
		// cout << (routr.size()) << endl;
		tmp_row = routr.top().row;
		tmp_col = routr.top().col;
		if (tmp_row == 0 || tmp_col == 0 || tmp_row == 9 || tmp_col == 9)break;
		if (check(tmp_row + 1, tmp_col)) {
			maze[tmp_row + 1][tmp_col] = 2;
			routr.push(Cordinate(tmp_row + 1, tmp_col));
			continue;
		}
		if (check(tmp_row, tmp_col + 1)) {
			maze[tmp_row][tmp_col + 1] = 2;
			routr.push(Cordinate(tmp_row, tmp_col + 1));
			continue;
		}
		if (check(tmp_row - 1, tmp_col)) {
			maze[tmp_row - 1][tmp_col] = 2;
			routr.push(Cordinate(tmp_row - 1, tmp_col));
			continue;
		}
		if (check(tmp_row, tmp_col - 1)) {
			maze[tmp_row][tmp_col - 1] = 2;
			routr.push(Cordinate(tmp_row, tmp_col - 1));
			continue;
		}
		routr.pop();
	}

	print();
	system("pause");
	return 0;
}
