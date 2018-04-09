#include<iostream>
using namespace std;
const int MAXSIZE = 10;
class SharedStack {
public:
	SharedStack() :top_a(-1),top_b(MAXSIZE) {};
	void push(int n, int data);
	int pop(int n);
	void print();
private:
	int top_a, top_b;
	int DATA[MAXSIZE];
};
void SharedStack::push(int n, int data) {
	if ((top_a + 1) != top_b) {
		if (n == 1) { top_a++;DATA[top_a] = data; }
		if (n == 2) { top_b--;DATA[top_b] = data; }
	}
}
int SharedStack::pop(int n) {
	if (top_a > -1 && n == 1) { top_a--;return DATA[top_a + 1]; }
	if (top_b < MAXSIZE && n == 2) { top_b++;return DATA[top_b - 1]; }
}
void SharedStack::print() {
	int tmp_a = top_a;
	int tmp_b = top_b;
	while (tmp_a>-1)
	{
		cout << DATA[tmp_a] << "  ";
		tmp_a--;
	}
	cout << endl;
	while (tmp_b<MAXSIZE)
	{
		cout << DATA[tmp_b] << "   ";
		tmp_b++;
	}
	cout << endl;
}
int main(int argc, char const *argv[]) {
	SharedStack st;
	st.push(1, 1);
	st.push(2, 1);
	st.push(1, 2);
	st.push(2, 2);
	st.push(2, 3);
	st.print();
	st.pop(1);
	st.pop(2);
	st.print();
	system("pause");
	return 0;
}
