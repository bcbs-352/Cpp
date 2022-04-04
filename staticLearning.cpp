#include <iostream>
using namespace std;

class OnlyHeapClass
{
public:
    static OnlyHeapClass *GetInstance()
    {
        cout << "create new OnlyHeapClass" << endl;
        return (new OnlyHeapClass);
    }
    void Destory()
    {
        cout << "delete object";
        delete this;
    }

private:
    OnlyHeapClass(){};
    ~OnlyHeapClass(){};
};

int main()
{
    // OnlyHeapClass A = new OnlyHeapClass();//error
    OnlyHeapClass *p = OnlyHeapClass::GetInstance();
    p->Destory();
    return 0;
}