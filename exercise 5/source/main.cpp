#include "swap.h"

int main()
{
    
    string str1 = "(string 1)";
    string str2 = "(string 2)";
    
    const Class1 object1(111111, &str1);
    const Class2 object2(222222, &str2);
    
    cout << "\n__________BEFORE SWAP:__________\n";
    object1.getContent();
    object2.getContent();
    cout << "________________________________\n";
    
    swap(object1, object2);
    
    cout << "\n__________AFTER SWAP:__________\n";
    object1.getContent();
    object2.getContent();
    cout << "________________________________\n";
    

    return 0;
}