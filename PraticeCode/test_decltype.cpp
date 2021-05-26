#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    decltype(a) b = 20.01;

    double c = 20.04;
    decltype(c) d = 15.6;

    cout << d << endl;
    system("pause");
    return 0;
}