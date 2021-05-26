/*******************************
 * Topic: 友元函数&友元类的使用
 * Author:Sliverchen
 * Create file date : 2021 / 5 / 25
 * Explanation:
 *      对于友元函数和友元类而言，
 *      它们都可以访问当前定义所在的类的所有成员（包括私有成员和受保护成员）
 *      
 * 要注意：
 *      友元函数没有this指针，因此想要对类的内部成员进行赋值首先需要告诉编译器在哪个类对象里
 *      友元函数不受当前定义的类的公有区域或私有区域所局限
 * ****************************/

#include <iostream>
using namespace std;
class B;

class A
{
    int x;

    friend void setX(A &classa, int a)
    {

        classa.x = a;
    }

    friend int getX(A &classa)
    {
        return classa.x;
    }

public:
    int getx()
    {
        return x;
    }
    void setx(int a)
    {
        x = a;
    }
    friend class B;
};

class B
{
public:
    void printA_X()
    {
        A classa;
        classa.x = 10;
        cout << classa.x << endl;
    }
};

int main()
{
    B classB;
    classB.printA_X();

    A classA;
    classA.setx(2);
    cout << classA.getx() << endl;
    cout << getX(classA) << endl;
    setX(classA, 0);
    cout << getX(classA) << endl;
    cout << classA.getx() << endl;

    system("pause");
    return 0;
}
