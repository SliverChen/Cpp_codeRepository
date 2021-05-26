/******************************
 * Topic:   Auto 和 decltype 的区别
 * 
 * Author:  Sliverchen
 * 
 * Create file date : 2021 / 5 / 24
 * 
******************************/

/*
    注意auto和decltype都是类型推断的方式
    区别在于：
    1、auto是通过编译器计算变量的初始值来推断其类型
    2、decltype则是让编译器分析它的表达式来推断其类型的

    3、auto会保留底层指针而忽略顶层指针
    4、decltype会保留顶层指针
    举例如下：
*/

#include <iostream>
using namespace std;

int main()
{
    const int a = 10;
    auto b = a;
    decltype(a) c = a;
    b++;
    //c++;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    system("pause");
    return 0;
}