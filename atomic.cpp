#include <iostream>
#include <atomic>
using namespace std;

int main()
{
    boolalpha(std::cout);
    std::atomic<int> count;

    count.store(0);

    int old = 0;
    bool equal = count.compare_exchange_strong(old, 3);
    cout << "equal" << equal << endl;
    cout << "old" << old << endl;

    int now = count.load();
    cout << "cnt" << now << endl;

    old = 2;
    equal = count.compare_exchange_strong(old, 3);
    cout << "equal" << equal << endl;
    cout << "old" << old << endl;

    now = count.load();
    cout << "cnt" << now << endl;
}