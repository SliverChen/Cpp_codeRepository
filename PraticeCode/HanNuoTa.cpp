/*
    Topic:汉诺塔问题
    Author: Sliverchen
    Create file date : 2021 / 4 / 23
*/

#include <cstring>
#include <iostream>
using namespace std;

void func(int N, string from, string to, string other)
{
    if (N == 1)
    {
        cout << "move 1 from " << from << " to " << to << endl;
        return;
    }

    func(N - 1, from, other, to);
    cout << "move " << N << " from " << from << " to " << to << endl;
    func(N - 1, other, to, from);
}

void HanNuoTa(int N)
{
    func(N, "left", "right", "mid");
}

int main()
{
    HanNuoTa(3);
    system("pause");
    return 0;
}