/*
    Topic:  How can we access the private member from one class to another class
    Explanation:
    
            while in the class that will be accessed, add friend xxx(the class u want to access it) in this class

                in this way, if the accessed class is defined previously compared to the class that wants to access
                before the accessed class, we should defined that xxx is a class type

                the example is as follows
*/

#include <iostream>
using namespace std;

class WantAccess;

class BeAccessed
{
private:
    void print1()
    {
        printf("the beAccessed_ex1 has been called\n");
    }
    friend WantAccess;
};

class WantAccess
{
public:
    void print1()
    {
        printf("the WantAccess_Ex1 has been called\n");
        ex1.print1();
    }

private:
    BeAccessed ex1;
};

int main()
{
    WantAccess ex1;
    ex1.print1();
    system("pause");
    return 0;
}