#include <iostream>

template <class T>
class Base
{
    friend T;

private:
    Base()
    {
        std::cout << "base" << std::endl;
    }
    ~Base();
};

class FinalClass : virtual public Base<FinalClass>
{
private:
    int data;

public:
    FinalClass()
    {
        std::cout << "finalClass" << std::endl;
    }
    ~FinalClass();
};

class c : public FinalClass
{
public:
    c(){};
};

int main()
{
    FinalClass f;
    return 0;
}
