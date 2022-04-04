#include"pzTest.hpp"
#include<iostream>

using namespace std;

void A::show(){
	cout<<"iii="<<i;
}

A func(int i){
	//A*a=new A(2);
	//return *a;
	A b(i);
	return b;
}

A fun(int i){
	A a(i);
	return a;
}

int main(){
	A c=func(2);
	c.	show();
	cout<<"cut"<<endl;
	return 0;
}
