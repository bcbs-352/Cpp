#include <stdio.h>
#include <memory>

struct C
{
    // int *p;
    C()
    {
        // int *p = (int *)malloc(1024);
        printf("malloc_p");
    }
    ~C()
    {
        // free(p);
        printf("free_p");
    }

    void member_func()
    {
        printf("\ndoSomething\n");
    }
};

void func(std::unique_ptr<C> p)
// void func(C *p)
{
    p->member_func();
}

int main()
{
    std::unique_ptr<C> p = std::make_unique<C>();
    // C c{};
    if (1)
    {
        // printf("\nsome problem");
        // func(p); // unique_ptr无法使用拷贝构造函数，无法直接调用成员函数
        // func(p.get());
        func(std::move(p));
        return 1;
    }
    return 0;
}