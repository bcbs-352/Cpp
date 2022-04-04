#include <iostream>
#include <string>

using namespace std;

class highPrecision
{
public:
    highPrecision() {}
    bool cmp(string &a, string &b);
    string Add(string a, string b);
    string Subtract(string a, string b);
    string Multiply(string a, string b);
    string Div(string a, long long b, int n);
    string Moudle(string a, string b);
    ~highPrecision()
    {
        delete[] this->c;
        c = nullptr;
    }

private:
    int *c = new int[10000001]; //记录结果的数组
    long k = 0, r = 0, i, j;    // k一直表示最高位
    bool flag = false;          //防止第一位输出0
};

bool highPrecision::cmp(string &a, string &b) //若a小，则交换ab，返回0
{
    if (a.size() < b.size() || (a.size() == b.size() && a < b))
    {
        swap(a, b); //大数在前
        return 0;
    }
    return 1;
}

string highPrecision::Add(string a, string b)
{
    cmp(a, b);
    //  if (a.size() < b.size() || a.size() == b.size() && a < b) //把大的字符串放前面，方便操作
    //{
    //  swap(a, b);
    // }
    k = 0;
    for (i = a.size() - 1, j = b.size() - 1; j >= 0; i--, j--)
    {
        c[k] = (r + a[i] - '0' + b[j] - '0') % 10; //存储结果
        int temp = c[k];
        k++;
        r = (r + a[i] - '0' + b[j] - '0') / 10; //存储进位
    }
    // b[j]='0'了，a中还有剩余的数,继续i--
    while (i >= 0)
    {
        c[k++] = (r + a[i] - '0') % 10;
        r = (r + a[i] - '0') / 10;
        i--;
    }
    if (r != 0)
        c[k++] = r;
    //输出,以i为指针,从高到低
    for (i = k - 1; i >= 0; i--)
    {
        if (c[i] != 0 || flag)
        {
            cout << c[i];
            flag = true;
        }
    }
    if (flag == false)
        cout << 0;
    // string str = (char *)c;
    return "done";
}

string highPrecision::Subtract(string a, string b)
{
    cmp(a, b);
    for (i = a.size() - 1, j = b.size() - 1; j >= 0; i--, j--)
    {
        c[k++] = (a[i] - b[j] - r); //从高位到低位，a-b-借位r
        r = 0;                      //借位
        if (c[k - 1] < 0)           //若相减的这位小于10了，借位进1，该位+10
        {
            c[k - 1] += 10;
            r = 1;
        }
        while (i >= 0) // a剩下的位数继续减
        {
            c[k++] = (a[i] - '0' - r);
            r = 0;
            if (c[k - 1] < 0)
            {
                c[k - 1] += 10;
                r = 1;
            }
        }
        for (i = k - 1; i >= 0; i--)
        {
            if (c[i] != 0 || flag)
            {
                cout << c[i];
                flag = true;
            }
        }
        if (flag == false)
            cout << 0;
    }
    string str = (char *)c;
    return str;
}

string highPrecision::Multiply(string a, string b)
{
    cmp(a, b);
    int len = a.size() + b.size();
    // cout << len;
    //  c[i+j]+=a[i]*b[j];
    for (int i = a.size() - 1; i >= 0; i--)
    {
        for (int j = b.size() - 1; j >= 0; j--)
        {
            c[i + j] += (a[i] - '0') * (b[j] - '0');
        }
    }
    for (k = a.size() + b.size(); k > 0; k--)
    {
        c[k] += c[k + 1] / 10;
        c[k + 1] %= 10;
    }
    for (k = 0; k <= len - 2; k++) // 一共len-1位数
    {
        cout << c[k];
    }
    // return "Multiply done";
    return (char *)c;
}
//高精度除以低精度
string highPrecision::Div(string s, long long b, int n)
{ // s被除数  b除数 a当前步结果
    long a;
    k = 0;
    for (int i = 0; i < s.size(); i++)
    {
        a = a * 10 + s[i] - '0'; //上一位*10加上c的当前位
        c[k++] = a / b;
        a %= b; //这一步算完的余数，保留到下一轮*10
    }
    for (int i = 0; i < k; i++)
    {
        if (c[i] != 0 || flag)
        {
            cout << c[i];
            flag = true;
        }
    }
    if (flag = false)
        cout << 1;
    return (char *)c;
}

int main()
{
    string a = "11131243892133";
    string b = "22233341343433333";
    // cout << a << "+\n"
    //<< b << "=" << endl;
    highPrecision *hp = new highPrecision();
    hp->Div(a, 4124, 0);
    // system("pause");
    return 0;
}
