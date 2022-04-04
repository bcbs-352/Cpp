#include"iostream"

class A{
	int i;
public:
    A(){i=0;}
    A(int _i){
        i=_i;
        ::std::cout<<"i="<<i;
    }	
    ~A(){
        ::std::cout<<"destory";
    }
    void show();
};