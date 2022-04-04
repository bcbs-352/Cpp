//#include <istream>
//#include <ostream>
#include <iostream>
#include <cstring>
using namespace std;
#define SIZE_OF_BUFFER 4096
class my_string
{
    friend ostream &operator<<(ostream &os, const my_string &str);
    friend istream &operator>>(istream &is, my_string &str);

public:
    my_string(const char *str = NULL);
    my_string(const my_string &);
    ~my_string();
    my_string operator=(const my_string &);
    my_string operator=(const char*ch);
    my_string operator+(const my_string &);
    bool operator==(const my_string &);
    char &operator[](int); //
    int size() { return strlen(this->data) + 1; }

//private:
    char *data;
};

my_string::my_string(const char*str)
{
    if (str == NULL)
        this->data = NULL;
    else
    {
        this->data = new char[strlen(str) + 1];
        strcpy(data, str);
    }
}

my_string::my_string(const my_string &other)
{
    if (other.data == NULL)
        this->data == NULL;
    else
    {
        this->data = new char[strlen(other.data) + 1];
        strcpy(this->data, other.data);
    }
}

my_string::~my_string()
{
    delete[] this->data;
    this->data = NULL;
}

my_string my_string::operator=(const my_string &other)
{
    delete[] this->data;
    if (other.data == NULL)
    {
        this->data = NULL;
    }
    else
    {
        this->data = new char[strlen(other.data) + 1];
        strcpy(this->data, other.data);
    }
    return *this;
}

my_string my_string::operator+(const my_string &other)
{
    if (other.data == NULL)
        return *this;
    else if (this->data == NULL)
    {
        this->data = new char[strlen(other.data) + 1];
        strcpy(this->data, other.data);
        return *this;
    }
    else
    {
        my_string strTmp;
        strTmp.data = new char[strlen(other.data) + 1];
        strcpy(strTmp.data, this->data);
        strcat(strTmp.data, other.data); //

        return strTmp; //不改变原来的string
    }
}

bool my_string::operator==(const my_string &str)
{
    if (strlen(data) != strlen(str.data))
        return false;

    if (strcmp(data, str.data) == 0)
        return true;
    return false;
}

char &my_string::operator[](int index)
{
    return this->data[index];
}

my_string my_string::operator=(const char*ch)
{
	//if(data!=NULL) delete[] data;
	data=new char[strlen(ch)+1];
	strcpy(data,ch);
	return*this;
} 

ostream &operator<<(ostream&os, const my_string &str)
{
    os << str.data;
    return os;
}

istream &operator>>(istream&is, my_string &str)
{
    char buffer[SIZE_OF_BUFFER];
    is >> buffer;
    str=buffer;
    return is;
}

int main(){
	my_string str("123");
	
	std::cout<<str;
}
