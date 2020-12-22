#include<iostream>
/*
Author: �²�Ǯ
Topic: BFS��DFSʵ�� 
*/
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define MAX 200

bool vis[MAX];  //��¼�Ѿ��߹��ĵ�



//int edge[MAX][MAX];
//��һ������Ч�ʵͣ�����1000��ʱ��Ϳռ䶼������ 


//vector<int> edge[100];
//edge[3].push_back(6)    //����һ����3��6�ı� 
//�ڶ��ֽ�Ϊ���� 

/*
�����ֽ������ 
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


//BFSʵ��(���ö��д�������ĵ�)
vector<int> E[100];  //��¼�� 
void BFS(int root)   //N�����ͼ����root��ʼ����
{
	queue<int> que;             //��ʼ�� 
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
		for(int i=0;i<len;i++) //�ҵ���u���������е㣬��ŵ�que�� 
			if(vis[E[u][i]]==0)
			{
				vis[E[u][i]]=1;
				que.push(E[u][i]);
				cout<<E[u][i]<<" ";
			 } 
	}
	
} 

//DFSʵ�� ��������ջ����Ϊ�����Ƚ��ȳ���Ҳ�����ú����ݹ飩
//�����ݹ�  Ч�ʽϵͣ�������� 
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

//ջʵ�� 
void DFS_stack(int root)
{
	stack<int> s;              //��ʼ�� 
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

