////////////////////////////////////////
/// function,bind,lamda基本用法
/// ////////////////////////////////////
#include <iostream>
#include <functional>
using std::function;
using std::bind;
class FunClassTest{
    public:
    void print(int i, int j){
        using std::cout;
        using std::endl;
        cout << i << j << endl;
    }
    int operator()(){
        return 1;
    }
};
int FunTest(){
    return 1;
}
void FunPrint(int i, int j){
    using std::cout;
    using std::endl;
    cout << i << j << endl;
}
int main(int argc, char const *argv[])
{
    // function
    FunClassTest c1;
    function<int()> ffun(c1);
    function<int()> fclass(FunTest);
    std::cout<<ffun()<<std::endl;
    std::cout<<fclass()<<std::endl;

    // bind
    FunClassTest c2;
    // bind 返回值为一个可调用对象
    auto fprint = bind(FunPrint, 8, std::placeholders::_1);
    auto fclassprint = bind(FunClassTest::print, c2, 8, std::placeholders::_1);
    fprint(1);
    fclassprint(1);

    // lamda
    function<double(float)> square = [](float i) -> double {return i*i;};
    std::cout << square(3.0f) << std::endl;

    {
        int x = 100;
        int x1 = 10;
        auto compare = [=](int i) -> bool {return i > x;}; // pass-by-value
        auto compare1 = [&](int i) -> bool {return i > x;}; // pass-by-reference
        auto compare = [=, &x1](int i) -> bool {return i > x;}; // default pass-by-value, x1 is pass-by-reference
        if (compare(1000))
            std::cout << "OK" << std::endl;
        else
            std::cout << "FAIL" << std::endl;
    }
    system("pause");
    return 0;
}