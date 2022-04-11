#include <iostream>
int num = 11;

int  func(){
    int num = 23;
    return num;
}


int main(){
    std::cout << func();
    return 0;
}