/************************************
 * Topic: 类的静态数据成员和静态成员函数的使用
 * Author: Sliverchen
 * Create file date : 2021 / 5 / 25
 * Explanation:
 * 1、对于类的静态数据成员
 *      类的静态数据成员是类所共享的
 *      也就是说如果目前有多个类对象创建，其中有一个对象对该数据成员赋值为1
 *      那么其他对象中的静态数据成员都会被赋值为1
 * 
 * 2、对于类的静态成员函数
 *      类的静态成员函数是所有对象共同享有的
 *      公有函数的调用方式：
 *          类名::函数名(参数表)
 *         或
 *          对象.函数名(参数表)
 *      作用：
 *          一般用于访问和设置静态数据成员
 * **********************************/

#include <iostream>
using namespace std;

class test
{
public:
    static void setA(int x)
    {
        A = x;
    }

    static int getA()
    {
        return A;
    }

private:
    static int A;
};

int test::A = 10; //在类外初始化

int main()
{
    test test1;
    test test2;
    cout << test1.getA() << endl; //获取test1的A值
    test1.setA(2);                //在test1中设置A值
    cout << test2.getA() << endl; //获取test2的A值
    system("pause");
    return 0;
}