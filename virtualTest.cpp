#include <iostream>
#include <string>
class Base
{
public:
    int num = 0;

public:
    Base() {}
    virtual void Vout(std::string str) { std::cout << "BaseV:" << str << std::endl; }
    void Rout(std::string str) { std::cout << "BaseR:" << str << std::endl; }
    ~Base() {}
};

class A : virtual public Base
{
public:
    A() {}
    virtual void Vout(std::string str) override;
    void Rout(std::string str, int n);
    void Rout(int n) { std::cout << "Aint:" << n << std::endl; }
    ~A() {}
};
void A::Rout(std::string str, int n)
{
    std::cout << str << n << std::endl;
}
void A::Vout(std::string str)
{
    std::cout << "Vout(A):" << str << std::endl;
}

class B : virtual public Base
{
public:
    B() {}
    virtual void Vout(std::string str) { std::cout << "BclassV:" << str << std::endl; }
    ~B() {}
};

class C : public A, public B
{

public:
    C() { num = 3; }
    void Vout(std::string str) { std::cout << "CclassV:" << str << std::endl; }
    void Cout() { std::cout << num++ << std::endl; }
    ~C() {}
};

int main()
{
    Base *basePtr = new Base;
    B *bPtr = new B;
    Base base;
    A a;
    B b;
    C c;
    base.Rout("base");
    // a.Rout(2);
    b.Vout("sss");
    *basePtr = b;
    basePtr->Rout("111");
    *bPtr = c;
    // std::cout << c.num;
    bPtr->Rout("bPtr");
    c.Rout(233);
    return 0;
}