#ifndef SWAP_H
#define SWAP_H

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

class Class1
    {
        private :
            
            int int1;
            string* str1;
            
        public :
            Class1();
            Class1(int v1, string* v2);
            Class1(const Class1& swapClass); // copy constructor
            Class1& operator=(const Class1& swapClass);
            void getContent() const;
            ~Class1();
    };
    

class Class2
    {
        private :
            
            int int2;
            string* str2;
            
        public :
            Class2();
            Class2(int v1, string* v2);
            Class2(const Class2& swapClass); // copy constructor
            Class2& operator=(const Class2& swapClass);
            void getContent() const;
            ~Class2();
    };

    template <typename T1, typename T2>
    
    void swap(const T1& object1, const T2& object2)
    {
        T1 tempT1 = object1;
        const_cast<T1&> (object1) = reinterpret_cast<T1&> (
                                    const_cast<T2&> (object2));
        const_cast<T2&> (object2) = reinterpret_cast<T2&> (tempT1);
    }


#endif