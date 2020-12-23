#include "swap.h"

Class1::Class1()
{
    int1 = 0;
    str1 = NULL;
}

Class1::Class1(int v1, string* v2)
{
    int1 = v1;
    str1 = v2;
}

Class1::Class1(const Class1& swapClass)
{
    *this = swapClass;
}

Class1& Class1::operator=(const Class1& swapClass)
{
    if (this != &swapClass)
    {
        int1 = swapClass.int1;
        str1 = swapClass.str1;
    }
    return *this;
}

void Class1::getContent() const
{
    cout << "Here is Class1: \n";
    cout << " 1) integer 1: " << int1 << endl;
    cout << "    integer 1 address: " << &int1 << endl;
    cout << " 2) string 1: " << *str1 << endl;
    cout << "    string 1 address: " << str1 << endl;
}


Class1::~Class1()
{
    int1 = 0;
    str1 = NULL;
}

Class2::Class2()
{
    int2 = 0;
    str2 = NULL;
}

Class2::Class2(int v1, string* v2)
{
    int2 = v1;
    str2 = v2;
}

Class2::Class2(const Class2& swapClass)
{
    *this = swapClass;
}

Class2& Class2::operator=(const Class2& swapClass)
{
    if (this != &swapClass)
    {
        int2 = swapClass.int2;
        str2 = swapClass.str2;
    }
    return *this;
}

void Class2::getContent() const
{
    cout << "Here is Class2: \n";
    cout << " 1) integer 2: " << int2 << endl;
    cout << "    integer 2 address: " << &int2 << endl;
    cout << " 2) string 2: " << str2 << endl;
    cout << "    string 2 address: " << str2 << endl;
}

Class2::~Class2()
{
    int2 = 0;
    str2 = 0;
}