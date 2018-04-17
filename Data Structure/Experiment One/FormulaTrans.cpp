#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<char> output;
vector<char> sta;
bool check(char tmp) {
	if (sta.empty()) {
		return true;
	}
	else if (tmp == '(') {
		return true;
	}
	return false;
}
int priority(char tmp) {
	if (tmp == '+' || tmp == '-')return 1;
	else if (tmp == '*' || tmp == '/')return 2;
	else return -1;
}
void transform(string formula) {
	for (auto i : formula) {
		if (int(i) >= 48 && int(i) <= 57) { //若为操作数直接输出
			output.emplace_back(i);
		}
		else if (check(i)) { //对于运算符当空栈和（直接入栈
			sta.emplace_back(i);
		}
		else if (i == ')') {
			while (sta.back() != '(') {
				output.emplace_back(sta.back());
				sta.pop_back();
			}
			sta.pop_back(); //将无用的（输出
		}
		else { //需要判断优先级的情况
			if (!sta.empty() && priority(sta.back()) >= priority(i)) {
				while (!sta.empty() && priority(sta.back()) >= priority(i)) {
					output.emplace_back(sta.back());
					sta.pop_back();
				}
				sta.emplace_back(i);
			}
			else {
				sta.emplace_back(i);
			}
		}
	}
	while (!sta.empty()) {
		output.emplace_back(sta.back());
		sta.pop_back();
	}
	for (auto i : output)cout << i;
}
void cal() {
	vector<int> data;

	// for (vector<char>::iterator it = begin(output);it<end(output);++it) {
	// 	if (int(*it) < 48 || int(*it) > 57) {
	// 		sta.emplace_back(*it);
	// 	}
	// 	else {
	// 		data.emplace_back(int(*it)-48);
	// 	}
	// }

	int num1, num2, ans;
	for (auto i : output) {
		if (int(i) >= 48 && int(i) <= 57) {
			data.emplace_back(int(i) - 48);
		}
		else {
			num1 = int(data.back());
			data.pop_back();
			num2 = int(data.back());
			data.pop_back();
			switch (i) {
			case '+':
				ans = num1 + num2;
				break;
			case '-':
				ans = num1 - num2;
				break;
			case '*':
				ans = num1*num2;
				break;
			case '/':
				ans = num1 / num2;
				break;
			}
      // cout<<num1<<num2<<endl;
			data.emplace_back(ans);
		}
	}
	cout << data.back();
}

int main(int argc, char const *argv[]) {
	string formula = "2+3*5";
	transform(formula);
	cout << endl;
	cal();
	system("pause");
	return 0;
}
