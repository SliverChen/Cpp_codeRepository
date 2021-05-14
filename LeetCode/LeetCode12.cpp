/*
    Topic: Int to Roman
    Author: Sliverchen
    Create file date : 2021 / 5 / 14
    Explanation:

*/

#include <cstring>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, string> themap;

void createMap()
{
    themap[1] = "I";
    themap[5] = "V";
    themap[10] = "X";
    themap[50] = "L";
    themap[100] = "C";
    themap[500] = "D";
    themap[1000] = "M";
    for (int i = 1; i < 1000; i = i * 10)
    {
        themap[4 * i] = themap[1 * i] + themap[5 * i];
        themap[9 * i] = themap[1 * i] + themap[10 * i];
    }
}

//傻逼解法
string inttoRoman(int num)
{
    string result = "";
    int i = 1000;
    while (i != 1)
    {
        if (num == 0)
            break;
        while (num / i == 0)
            i = i / 10;
        int curNum = num / i;
        if (curNum == 4 || curNum == 9)
        {
            result += themap[i * curNum];
            num = num - curNum * i;
            continue;
        }
        else if (curNum > 5) //如果当前位的位数比5大
        {
            result += themap[i * 5];
            curNum = curNum - 5;
        }
        for (int j = 0; j < curNum; j++)
            result += themap[i];
        num = num - num / i * i;
    }
    return result;
}

const string thousand[] = {"", "M", "MM", "MMM"};
const string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
const string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
const string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

//简单暴力解法
//（硬编码数字）
string IntToRoman(int num)
{
    return thousand[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
}

int main()
{
    createMap();
    cout << inttoRoman(9) << endl;
    cout << inttoRoman(6) << endl;
    cout << inttoRoman(4) << endl;
    cout << inttoRoman(10) << endl;
    cout << inttoRoman(103) << endl;
    cout << IntToRoman(10) << endl;
    system("pause");
    return 0;
}