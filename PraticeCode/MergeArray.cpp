/*
Topic:Merge array a and array b
Statement:
    1、use memcpy to achieve merging
        create another array c which size = a.size + b.size
        memcpy(c,a,sizeof(a));
        memcpy(c+a.size,b,sizeof(b));
            c.insert(c.end(),a.begin(),a.end());

    2、if array belong to Vector,use   insert   or   merge   (a,b,c are belonged to vector)
        (1)while using insert:(use iterator vector.begin() and vector.end())
            c.insert(c.end(),b.begin(),b.end());

        (2)while using merge:  (#include<algorithm> ---> in order to use function sort and merge)
            sort(a.begin(),a.end());   //the array a and b must be sorted before using merge
            sort(b.begin(),b.end());
            c.resize(a.size+b.size);   //the size of array c should be defined previously
            merge(a.begin(),a.end(),b.begin(),b.end(),c.begin());   //merge start at c.begin(), not c.end()
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int a[3]={1,2,3};
    int b[4] ={4,5,6,7};
    int c[7];
    memcpy(c,a,3*sizeof(int));
    memcpy(c+3,b,4*sizeof(int));
    printf("while using memcpy to merge two arrays: \n");
    for (auto ar:c)
    {
        printf("%d ", ar);
    }
    printf("\n");

    printf("while using insert to merge two vectors: \n");
    vector<int> a1 = {1, 2, 3, 4};
    vector<int> b1 = {2, 4, 5};

    vector<int> c1;
    c1.insert(c1.end(), a1.begin(), a1.end());
    c1.insert(c1.end(), b1.begin(), b1.end());
    for(auto value:c1)
    {
        printf("%d ", value);
    }
    printf("\n");

    printf("while using merge to merge two vectors: \n");
    vector<int> c2;
    c2.resize(a1.size() + b1.size());
    sort(a1.begin(), a1.end());
    sort(b1.begin(), b1.end());
    merge(a1.begin(), a1.end(), b1.begin(), b1.end(), c2.begin());
    for(auto value:c2)
    {
        printf("%d ", value);
    }
    printf("\n");

    system("pause");
    return 0;
}