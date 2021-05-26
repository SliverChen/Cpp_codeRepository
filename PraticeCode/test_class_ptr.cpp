/***********************************
 * Topic: 类成员函数指针的使用
 * Author: Sliverchen
 * Create file date : 2021 / 5 / 25
 * Explanation:
 *  需要注意的是：
 *  1、类成员函数指针只能指向公有成员
 *  2、声明格式：
 *      返回值 (类名::*指针名)(参数类型)
 *  
 *  3、赋值格式：
 *      指针名 = &类名::函数名
 * 
 * 
 * *********************************/

#include <iostream>
using namespace std;

class test
{
public:
    void printA()
    {
        cout << "A" << endl;
    }
};

int main()
{
    void (test::*pFunc)();
    test mytest;
    pFunc = &test::printA;
    (mytest.*pFunc)();
    system("pause");
    return 0;
}