#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <chrono>
#include <typeinfo>
using namespace std;
class Base{
  public:
  void test();
  void test(int i);
};
class Derived:public Base{
  public:
  /*using Base::test;*/
  void test();
};
int main()
{
  system("pause");
  return 0;
}