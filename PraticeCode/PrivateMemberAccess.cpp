/*
    Topic:  How can we access the private member from one class to another class
    Explanation:
        there are three ways to achieve:
            1) while in the class that will be accessed, add friend xxx(the class u want to access it) in this class

                in this way, if the accessed class is defined previously compared to the class that wants to access
                before the accessed class, we should defined that xxx is a class type

                the example is as follows example one.


            2) make the class that will be accessed into the class u want to access as private member

                this way is only suitble for the accessed class is only correlated with this class

                the example is as follows example two
*/

#include <iostream>
using namespace std;

class WantAccess_Ex1;

class BeAccessed_Ex1
{
private:
    void print1()
    {
        printf("the beAccessed_ex1 has been called\n");
    }
    friend WantAccess_Ex1;
};

class WantAccess_Ex1
{
public:
    void print1()
    {
        printf("the WantAccess_Ex1 has been called\n");
        ex1.print1();
    }

private:
    BeAccessed_Ex1 ex1;
};

class WantAccess_Ex2
{
public:
    void print2()
    {
        printf("the WantAccess_Ex2 has been called\n");
        ex2.print2();
    }

private:
    class BeAccessed_Ex2
    {
    private:
        void print2()
        {
            printf("the BeAccessed_Ex2 has been called\n");
        }
    };
    BeAccessed_Ex2 ex2;
};