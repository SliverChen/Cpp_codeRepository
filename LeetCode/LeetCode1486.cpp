/*
    Topic: array XOR
    Author:Sliverchen
    Create file date: 2021 / 5 / 7
    Explanation:
*/

#include <iostream>
#include <vector>
using namespace std;

int xorOperation(int n, int start)
{
    int preValue = start, curValue;
    int i = 1;
    int result = preValue;
    while (i < n)
    {
        curValue = start + 2 * i;
        result = result ^ curValue;
        preValue = curValue;
        i++;
    }
    return result;
}

int main()
{
    cout << xorOperation(5, 0) << endl;
    system("pause");
    return 0;
}