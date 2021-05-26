/*
Topic:  How to input mutiple datas in one line
statement:
        1、use loop "for" and cin to finish this operation   
        (this way can't not input any number of data, which must limit the number of data previously)
            particularly:
                if we want to input 10 datas:
                    for(int i=0;i<10;i++)
                    {
                        cin>>data;
                    }

        2、use cin.get()!='\n' to finish this operation
        (this way can input any number we want, stop inputing when we push the botton "Enter")
            particularly:
                while(cin>>data)
                {
                    //..put data into data structure
                    if(cin.get()=='\n')
                        break;
                }
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> inputData_inway1;
    vector<int> inputData_inway2;
    int data;

    //way one
    // if we want to input 5 datas into data structure
    for (int i = 0; i < 5; i++)
    {
        cin >> data;
        inputData_inway1.push_back(data);
    }

    for (auto data : inputData_inway1)
    {
        printf("%d ", data);
    }
    printf("\n");

    // way two
    while (cin >> data)
    {
        inputData_inway2.push_back(data);
        if (cin.get() == '\n')
            break;
    }
    for (auto data : inputData_inway2)
    {
        printf("%d ", data);
    }
    printf("\n");
    system("pause");
    return 0;
}