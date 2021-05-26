/*
    Topic:decode XOR array by using 前n个正整数构成的数组
    Author:Sliverchen
    Create file date : 2021 / 5 / 11
*/

#include <iostream>
#include <vector>
using namespace std;

/*
    出于对题目的初步理解，我们尝试利用暴力枚举的方法进行
    首先从题目我们了解到这里没有提示第一个元素是什么，只给了异或后的数组
    也就是说我们知道了异或后的数组大小，由此我们可以得到异或前的数组大小为异或后+1
    
    注意这里要的结果集是由前n个正整数构成的，n是异或前的数组大小
    因此我们可以从1开始（正整数限定）作为异或前数组的第一个元素
    然后根据XOR算法得到后面的元素

    在遍历过程中，如果遇到比n要大或者为0的元素，那么我们可以直接舍弃掉这个情况
    因为题目说明了答案存在且唯一，所以我们只需遍历所有情况必然就有最优集
*/

vector<int> decode(vector<int> &encoded)
{
    int encodedSize = encoded.size();
    vector<int> result;
    for (int i = 1; i <= encodedSize + 1; ++i)
    {
        result.push_back(i);
        int next = i;
        for (int j = 0; j < encodedSize; ++j)
        {
            next = encoded[j] ^ next;
            if (next == 0 || next > encodedSize)
            {
                result.clear();
                break;
            }
            result.push_back(next);
        }
        if (result.size() % 2 == 0 || result.size() != encodedSize + 1)
        {
            result.clear();
            continue;
        }
        else
        {
            break;
        }
    }
    return result;
}

/*
    但是暴力枚举的缺点也比较明显:
    如果得到encoded的大小为254，即结果集中元素最大为255
    而我们的枚举从1开始，碰巧最优集的第一个元素是255，
    那么就要遍历255次encoded，此时的时间复杂度为O(n^2)
*/

/*
    为此我们需要对遍历优化：
    首先要思考：
        我们能否在O(n)情况下得到结果集？
        1）如果上述描述成立，我们又如何判断当前计算结果是最优集的一部分？
        2）如果上述描述不成立，我们能否在暴力枚举的基础上减少一些不必要的遍历？
    我们还需要注意一点：
        根据题目可知结果集是前n个正整数的排列，也就是说不存在重复元素
        不过利用上面的暴力枚举法能够成功通过62/63的测试用例，这个问题不需要考虑

    根据之前做过的Leetcode1720来看，关键是第一个元素的选取
    只要第一个元素确定了后面的元素也跟着确定了

    所以我们当前考虑的是如何找到最优集中的第一个元素
    怎么判断当前所遍历的数值就是最优集中的第一个元素？


    看不懂的优化：
        取X=从1一直异或到n
        最优集的第一个元素即为X xor encoded[1] xor encoded[3] ... xor encoded[n-1]

    在提示中给了我们两个问题：
        1）从1一直异或到n的这个结果会怎么用到
        2）为什么n是奇数

        关键是知道异或的性质以及规律
        
        1）首先异或符合结合律，即(a^b)^c = a^(b^c)
           由题目可知结果集是由前n个正整数排列构成，即元素是固定的，那么我们对这n个元素逐个异或，满足以下等式：
               total = 1^2^...^n = result[0]^result[1]^...^result[n-1]
        2）这道题关键是得到结果集的第一个元素，那么除掉第一个元素，剩下的n-1个元素构成一个偶数个数的结果集new_result
        根据题目encoded[i] = result[i]^result[i+1]可知
            new_result中必然构成encoded中n-1/2个元素
        因此我们可以举个例子进一步分析：
            encoded = [6,5,4,6]   result = [2,4,1,5,3]  new_result = [4,1,5,3]
        不难得出：
            encoded[1] = new_result[0] ^ new_result[1] = result[1] ^ result[2]

            encoded[2] = new_result[1] ^ new_result[2] = result[2] ^ result[3]
            
            encoded[3] = new_result[2] ^ new_result[3] = result[3] ^ result[4]

        我们可以发现：
        
            result[1]^result[2]^result[3]^result[4] = encoded[1]^encoded[3]

        再结合（1）的性质可得
            result[0]^encoded[1]^encoded[3] = total = 1^2^...^n
        交换位置可得：
            result[0] = 1^2...^n^encoded[1]^encoded[3]
        这样我们就得到了最优集中的第一个元素
*/

//时间复杂度为O(n)
vector<int> decode2(vector<int> encoded)
{
    int encodedSize = encoded.size();
    int n = encodedSize + 1;
    int x = 1;
    for (int i = 2; i <= n; i++) //遍历n次
        x = x ^ i;
    vector<int> result;
    result.push_back(x);
    int next = x;
    for (int i = 0; i < encodedSize; i++) //遍历n-1次
    {
        next = x ^ encoded[i];
        result.push_back(next);
    }
    return result;
}
