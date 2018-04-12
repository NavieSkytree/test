#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;
// 设计一个算术四则运算表达式求值的简单计算器。表达式求值是程序设计语言编译中最近本的问题，它要求把一个表达式翻译成能够直接求值的序列。
// 基本要求：
// 1、	输入中缀表达式能够转化成后缀表达式，比如输入中缀表达式
// “(A+B)*C”，输出“AB+C*”
// 2、操作数使用单字母变量A、B、C等表示，操作符仅为+、-、*、/、（和）；
// 3、能够对变量A、B、C等赋值，得出正确的计算结果
stack<string> s1;
queue<string> s2;
bool check(string s){
  if(s=="(") return true;
  if(!s1.empty())return true;
  if(s1.top()=="+" || s1.top()=="-"){
    if(s=="*" || s=="/")
    return true;
  }
  return false;
}
int main(int argc, char const *argv[]) {
  string cal="a0A";
  for(auto i:cal){
    cout<<(int)cal;
  }
  return 0;
}
