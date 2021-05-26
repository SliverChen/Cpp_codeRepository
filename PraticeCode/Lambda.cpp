/*
    Topic：C++的匿名函数使用
    Author:Sliverchen
    Create file date : 2021 / 5 / 21
    Explanation:
        匿名函数的格式如下：
            auto 函数名 = [捕获列表](参数列表){函数体};
        捕获列表的可选类型如下：
            []:默认不捕获任何变量
            [=]:默认以值捕获所有变量
            [&]:默认以引用捕获所有变量
            [x]:仅以值捕获x，其他变量不捕获
            [&x]:仅以引用捕获x，其他变量不捕获
            [=,&x]:默认以值捕获所有变量，但是x是例外，用引用捕获
            [&,x]:默认以引用捕获所有除x以外所有的变量，而x则通过值捕获
            [this]:通过引用捕获当前对象（即复制指针）
            [*this]:通过传值方式捕获当前对象
*/

#include <iostream>
using namespace std;

auto compare = [&](int a, int b) {
    return a > b ? a : b;
};

int main()
{
    cout << compare(2, 3);
    system("pause");
    return 0;
}