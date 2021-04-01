/*
Topic: 左值与右值的本质区别->能够对表达式用&符进行取址
*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
   int x = 0;
   cout << (&x) << endl;
   cout << (&++x) << endl;
   cout << (&x) << endl;
   x++;
   //cout<<(&x++)<<endl; error
   /*
   原因：++x的结果为左值，该表达式修改自身并返回自身
        x++的结果为右值，该表达式先创建一个临时对象，为其赋值，再返回临时对象
   */

   int y[10];
   int *p;
   p = y;
   cout << *p << *(p + 1) << endl;
   system("pause");
   return 0;
}