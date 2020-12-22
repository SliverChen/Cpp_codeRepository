#include<iostream>
/*
Author: 陈伯钱
Topic: BFS、DFS实现 
*/
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define MAX 200

bool vis[MAX];  //记录已经走过的点



//int edge[MAX][MAX];
//第一种这种效率低，超过1000个时间和空间都不允许 


//vector<int> edge[100];
//edge[3].push_back(6)    //代表一条从3到6的边 
//第二种较为常用 

/*
第三种较难理解 
struct Edge
{
	int to,next;
};

Edge E[1000];
int point[110],Ecou;

void init()
{
	memset(point,-1,sizeof(point));
	Ecou=0;
}

void addEdge(int u,int v)
{
	E[Ecou].to = v;
	E[Ecou].next = point[u];
	point[u] = Ecou++;
}

*/


//BFS实现(利用队列存放相连的点)
vector<int> E[100];  //记录边 
void BFS(int root)   //N个点的图，从root开始搜索
{
	queue<int> que;             //初始化 
	memset(vis,0,sizeof(vis));
	vis[root] = 1;
	que.push(root);
	cout<<root<<" ";
	int u,len;
	while(!que.empty())
	{
		u = que.front();
		que.pop();
		
		len = E[u].size();
		for(int i=0;i<len;i++) //找到和u相连的所有点，存放到que中 
			if(vis[E[u][i]]==0)
			{
				vis[E[u][i]]=1;
				que.push(E[u][i]);
				cout<<E[u][i]<<" ";
			 } 
	}
	
} 

//DFS实现 （可以用栈，因为符合先进先出；也可以用函数递归）
//函数递归  效率较低，差错不容易 
void DFS(int root)
{
	int len;
	vis[root] = 1;
	cout<<root<<" ";
	len = E[root].size();
	
	for(int i=0;i<len;i++)
		if(vis[E[root][i]]==0)
			DFS(E[root][i]);
}

//栈实现 
void DFS_stack(int root)
{
	stack<int> s;              //初始化 
	memset(vis,0,sizeof(vis));
	vis[root] = 1;
	s.push(root);
	cout<<root<<" ";
	
	bool is_push;
	
	while(!s.empty())
	{
		is_push = false;
		int top = s.top();
		int n = E[top].size();
		for(int i=0;i<n;i++)
		{
			if(vis[E[top][i]]==0)
			{
				vis[E[top][i]]=1;
				cout<<E[top][i]<<" ";
				s.push(E[top][i]);
				is_push = true;
				break;
			}
		}
		if(!is_push)
		{
			s.pop();
		}
	}	
}


int main()
{
	E[1].push_back(2);
	E[1].push_back(5);
	E[2].push_back(1);
	E[2].push_back(3);
	E[2].push_back(5);
	E[3].push_back(2);
	E[3].push_back(4);
	E[4].push_back(3);
	E[4].push_back(5);
	E[4].push_back(6);
	E[5].push_back(1);
	E[5].push_back(2);
	E[5].push_back(4);
	E[6].push_back(4);
	
	BFS(1);
	cout<<endl;
	
	memset(vis,0,sizeof(vis));
	DFS(1);
	cout<<endl;
	
	DFS_stack(1);
	cout<<endl;
	
	return 0;
}

