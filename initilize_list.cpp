#include <iostream>
#include <vector>
#include <map>

class Foo{
public:
    Foo(std::initializer_list <int>){}
};

class FooVector{
    std::vector<int> content_;
public:
    FooVector(std::initializer_list<int> list){
        for(auto it=list.begin();it !=list.end();it++){
            content_.push_back(*it);
        }
    }
};

class Foomap{
    std::map<int,int> content_;
    using pair_t=std::map<int,int>::value_type;
    //重新命名类型
public:
    Foomap(std::initializer_list<pair_t> list){
        for (auto it=list.begin();it != list.end();it++){
            content_.insert(*it);
        }
    }
};

void test1(){
    Foo foo={1,2,3,4,5};
    FooVector foo1={1,2,3,4,5};
    Foomap foo2={{1,2},{3,4},{5,6}};
}

void func(std::initializer_list<int> list){
    std::cout<<"size="<<list.size()<<std::endl;
    for(auto it =list.begin();it != list.end();it++){
        std::cout<<*it<<std::endl;
    }
}

void test2(){
    func({});
    func({1,2,3});
}

std::initializer_list<int> func2(void){
    int a=1,b=2;
    return {a,b};
}

std::vector<int>func3(void){
    int a=1,b=2;
    return{a,b};
}

void test3(){
    std::initializer_list<int> myList;
    size_t n=myList.size();
    myList={1,2,3,4,5};
    n=myList.size();
    myList={11,22};
    n=myList.size();

    std::vector<int> a;
    a=func2();
    a=func3();
}
 
 int main(void){
     test1();
     test2();
     test3();
     system("pause");
     return 0;
 }


