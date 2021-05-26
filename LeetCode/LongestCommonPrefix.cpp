/*
    Topic: the longest common prefix
    Statement:
        the prefix will be finded from the left side, if we can not match any char from left to right, we can indirectly break the circle
*/

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int getMinsize(vector<string> strArray)
{
    int minsize = INT_MAX;
    for (string str : strArray)
    {
        if (str.size() < minsize)
            minsize = str.size();
    }
    return minsize;
}

string findPrefix(vector<string> strArray)
{
    if (strArray.size() == 0)
        return "";
    if (strArray.size() == 1)
        return strArray[0];
    char *commonStr = new char[200];
    int index = 0;
    string result;
    char curChar;
    for (int i = 0; i < getMinsize(strArray); i++)
    {
        curChar = strArray[0][i];
        for (string str : strArray)
        {
            if (curChar != str[i])
            {
                commonStr[index] = '\0';
                result = commonStr;
                return result;
            }
        }
        commonStr[index++] = curChar;
    }
    commonStr[index] = '\0';
    result = commonStr;
    return result;
}

int main()
{
    vector<string> str_arr = {"car", "dog", "precar"};
    string prefix = findPrefix(str_arr);
    cout << prefix << endl;
    system("pause");
    return 0;
}