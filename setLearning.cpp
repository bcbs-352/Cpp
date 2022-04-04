#include <set>
#include <iostream>

using namespace std;
int main()
{
    set<int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    // set<int>::iterator it;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        printf("%d\n", *it);
    }
    cout << "begin" << *s.begin() << endl;
    cout << "lower_bound 3" << *s.lower_bound(3) << endl;//指向大于
    cout << "upper_bound 3" << *s.upper_bound(3) << endl;
    cout << "find() 3" << *s.find(3) << endl;
    cout << "s.size()" << s.size() << endl;

    return 0;
}