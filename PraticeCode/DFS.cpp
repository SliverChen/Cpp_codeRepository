/*
    Topic: DFS的递归实现和非递归实现
    Author: Sliverchen
    Create file date: 2021 / 5 / 18
*/

#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
using namespace std;

class solve
{
public:
    void BFS(int root)
    {
        initialize();
        queue<int> que;
        vis[root] = 1;
        que.push(root);
        cout << root << " ";
        int u, len;
        while (!que.empty())
        {
            u = que.front();
            que.pop();

            len = E[u].size();
            for (int i = 0; i < len; ++i)
            {
                if (vis[E[u][i]] == 0)
                {
                    vis[E[u][i]] = 1;
                    que.push(E[u][i]);
                    cout << E[u][i] << " ";
                }
            }
        }
        initialize();
        cout << endl;
    }

    void DFS(int root)
    {
        int len;
        vis[root] = 1;
        cout << root << " ";
        len = E[root].size();

        for (int i = 0; i < len; ++i)
        {
            if (vis[E[root][i]] == 0)
                DFS(E[root][i]);
        }
    }

    void DFS_Stack(int root)
    {
        stack<int> s;
        initialize();
        vis[root] = 1;
        s.push(root);
        cout << root << " ";

        bool is_push;

        while (!s.empty())
        {
            is_push = false;
            int top = s.top();
            int n = E[top].size();
            for (int i = 0; i < n; ++i)
            {
                if (vis[E[top][i]] == 0)
                {
                    is_push = true;
                    vis[E[top][i]] = 1;
                    cout << E[top][i] << " ";
                    s.push(E[top][i]);
                    break;
                }
            }
            if (!is_push)
                s.pop();
        }
        cout << endl;
    }

    void createGraph()
    {
        int from, to;
        int times;
        cin >> times;
        for (int i = 0; i < times; ++i)
        {
            cin >> from >> to;
            E[from].push_back(to);
        }
    }

    void initialize()
    {
        memset(vis, 0, sizeof(vis));
    }

private:
    vector<int> E[10];
    bool vis[10];
};

int main()
{
    solve mysolve;
    mysolve.createGraph();
    mysolve.BFS(1);
    mysolve.DFS(1);
    cout << endl;
    mysolve.DFS_Stack(1);
    system("pause");
    return 0;
}