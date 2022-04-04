#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

int add(int a, int b) { return a + b; }

// lambda
auto mod = [](int a, int b)
{ return a % b; };

struct divide
{
    int operator()(int denominator, int divisor)
    {
        return denominator / divisor;
    }
};

// std::function是一个可调用对象包装器，是一个类模板，可以出了容纳类对象成员函数指针之外的左右可调用对象
//它可以用统一的方式处理函数、对象、指针，并允许保存和延迟执行
//可以取代函数指针的作用，因为可以延迟函数的执行，特别是和作为回调函数使用
std::function<int(int, int)> a = add;
std::function<int(int, int)> b = mod;
std::function<int(int, int)> c = divide();
// std::bind可以看作一个通用的函数适配器
//接受一个可调用对象，生成一个新的可调用对象来“适应”原对象的参数列表

// bind绑定普通函数
double my_devide(double x, double y) { return x / y; }
std::function<double(double, double)> para1;
auto fn_half = std::bind(my_devide, para1, 2);

// bind一个成员函数
struct Foo
{
    void print_sum(int n1, int n2)
    {
        cout << n1 + n2 << endl;
    }
    int data = 10;
};
int main()
{
    Foo foo;
    auto f = std::bind(&Foo::print_sum, &foo, 95, std::placeholders::_1);
    f(5);
}