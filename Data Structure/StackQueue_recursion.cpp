#include<iostream>
using namespace std;
int factorial(int n) {
	if (!n)return 1;
	else return n*factorial(n - 1);
}
int fib(int n) {
	if (n == 1 || n == 2)return 1;
	else return fib(n - 1) + fib(n - 2);
}
void move(char x,char z){
	static int i;
	i++;
	cout << i << ":" << x << "->" << z << endl;
}
void hanoi(int n,char x,char y,char z){
	if (1 == n)move(x, z);
	else
	{
		hanoi(n - 1, x, z, y);
		move(x, z);
		hanoi(n - 1, y, x, z);
	}
}
int main(int argc, char const *argv[]) {
	cout << "factorial:" << factorial(5) << endl;
	cout<<"Fib:"<<fib(5)<<endl;
	int num;
	cout << "Input numbers:";
	cin >> num;
	hanoi(num, 'A', 'B', 'C');
	system("pause");
	return 0;
}
