#include<iostream>
#include<vector>
#include<queue>
#define N 10
using namespace std;
vector<int> adj[N];
bool vis[N];
int x, y, m, n;
void init()
{
	for (int i = 0; i < N; i++)
	{
		vis[i] = 0;
	}
}
void create()
{
	cout << "\n Enter the node and edge";
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cout << "\nEnter the edge";
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

}
void bfs()
{
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	while (!q.empty())
	{
		int node = q.front();
		cout << "\t" << node;
		q.pop();
		vector<int>::iterator it;
		for (it = adj[node].begin(); it < adj[node].end(); it++)
		{
			if (!vis[*it])
			{
				vis[*it] = 1;
				q.push(*it);
			}
		}
	}
}
void dfs(int node)
{
	vis[node] = 1;
	cout << "\t" << node;
	vector<int>::iterator it;
	for (it = adj[node].begin(); it < adj[node].end(); it++)
	{
		if (!vis[*it])
		{
			vis[*it] = 1;
			dfs(*it);
		}
	}

}
int main()
{
	int ch;
	char c;
	
	do
	{
		cout<<"1.dfs\n2.bfs \n"; 
        cout<<"choice :";
		cin >> ch;
		switch (ch)
		{
		case 1:
			init();
			create();
			dfs(1);
			break;
		case 2:
			init();
			create();
			bfs();
			break;

		default:
			cout << "\n Enter the valid choice";
		
		}
		cout<<"\n Do you want to continue enter y: ";
		cin >> c;

	} while (c=='y' ||c=='Y');

}