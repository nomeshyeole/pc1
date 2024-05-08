#include <iostream>
#include <stack>
using namespace std;


class Graph
{
    int v;
    int a[10][10];   //undirected graph

    public:
    Graph(int v)
    {
        this->v=v;
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                a[i][j]=0;
            }
        }
    }

    void addEdge(int u,int v);
    void BFS(int start);
    void DFS(int start);
    void display();

};

void Graph::display()
{
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

void Graph::addEdge(int u, int v)
{
    a[u][v]=1;
    a[v][u]=1;
}

void Graph::BFS(int start)
{
    int visited[10]={0};
    int queue[10];
    int front=0, rear=0;

    queue[rear++]=start;
    visited[start]=1;

    while(front!=rear)     //while(queue not empty)
    {
        int vertex=queue[front++];   //print visited node
        cout<<vertex<<"\t";


        for(int i=0;i<v;i++)
    {
        if((a[vertex][i]==1) && !visited[i])   //add adjacent nodes of visited to queue
        {
            queue[rear++]=i;
            visited[i]=1;
        }
    }
    }   

}

void Graph::DFS(int start)
{
    int visited[v]={0};
    std::stack<int> stack;

    stack.push(start);  //push start node in stack
    visited[start]=1;   // mark it as visited

    while(!stack.empty())  //while(stack not empty)
    {
        int vertex=stack.top();  // print and pop top element
        stack.pop();
        cout<<vertex<<"\t";

        for(int i=0;i<v;i++)
        {
            if( (a[vertex][i]==1) && (!visited[i]))
            {
                stack.push(i);  //push adjacent nodes of top node into stack
                visited[i]=1;
            }
        }
    }
    
}

int main()
{
    int v,u;
    char ans='y';
    cout<<"Enter number of nodes:";
    cin>>v;

    Graph g(v);

    do
    {
    cout<<"Select 2 nodes to add edge";
    cin>>u>>v;
    g.addEdge(u,v);
    cout<<"Add more Edges? y/n \n";
    cin>>ans;
    }while(ans=='y');

    g.display();

    cout<<"Select start node:";
    cin>>v;
    cout<<"BFS Traversal:";
    g.BFS(v);
    cout<<"DFS Traversal:";
    g.DFS(v);

    return 0;
}