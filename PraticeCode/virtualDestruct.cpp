/*
    Topic:Vritual desturct function 
    Author: Sliverchen
    Create file Date: 2021/4/21
    Explanation:
        while in C++ Polymorphism, the destructor function of the basic class should be add virtual prefix as "virtual ~destructor()"
        
        if we don't add virtual in front of it, when destruct the inherited class,
             it can only call the destructor function of the basic class.
        This can cause the inherited class not be destructed, which is call "memory leak"
*/

#include <iostream>
using namespace std;

class base
{
public:
    base() {}
    ~base() { cout << "base destructor called!" << endl; } //this can lead to memory leak
    //virtual ~base() { cout << "base destructor called!" << endl; }
};

class inherited : public base
{
public:
    inherited() {}
    ~inherited() { cout << "Inherited destructor called!" << endl; }
};

int main()
{
    base *myinherited1 = new base();
    base *myinherited2 = new inherited(); //内存泄漏容易出现在类型为基类的指针指向继承类的变量中
    inherited *myinherited3 = new inherited();
    delete myinherited1;
    delete myinherited2;
    delete myinherited3;
    system("pause");
    return 0;
}
