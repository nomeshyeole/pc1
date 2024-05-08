#include<iostream>
#include<queue>
using namespace std;


struct node
{
    string c;
    node *next;

};
class graph
{   public:
    int x;
    graph()
    {
     cout<<"enter total no of nodes ";
     cin>>x;
    }
    node* head[10];
    int visited[10];
    void initalize();
    void create();
    void bfs();
    void dfs();
    void DFSUtil(int);
};
 void graph:: initalize()
    {
        for(int i=0;i<x;i++)
        {
            head[i]=new node;
            head[i]->c='x';
            head[i]->next=NULL;
        }
    }
    void graph::create()
    {
        
        int n,i;
        node* temp;
        for (i=0;i<x;i++)
        {
            cout<<"enter a node";
            cin>>head[i]->c;
            cout<<"total node connected to it";
            cin>>n;
            for (int j=0;j<n;j++)
            {
                node *nnode=new node;
                cout<<"enter a node";
                cin>>nnode->c;
                nnode->next=NULL;
                temp=head[i];
                while(temp->next!=NULL)
                {
                    temp=temp->next;

                }
                temp->next=nnode;
            }
        {
        }
    }
    }


    void graph::bfs()
    {
       string a;
       node* temp;
       a=head[0]->c;
       cout<<" "<<a;
       for(int j=0;j<x;j++)
       {
        temp =head [j];
       while(temp->next!=NULL)
       {
         temp=temp->next;
        cout<<" "<<(temp->c);
       
        }
       }
    }


    void graph::DFSUtil(int v) {

    cout << head[v]->c<<" ";
    visited[v] = 1;
    node* temp = head[v]->next;
    while (temp!= NULL) {
        int i = 0;
        while (temp->c != head[i]->c)
            i++;
        if (!visited[i])
            DFSUtil(i);
        temp = temp->next;
    }
}

void graph::dfs() {
    for (int i = 0; i < x; i++)
        visited[i] = 0;
    for (int i = 0; i < x; i++)
        if (!visited[i])
            DFSUtil(i);
}

int main()
{
    graph g1;
    g1.initalize();
    g1.create();
    cout<<"BFS"<<"\n";
    
    g1. bfs();
    cout<<"\n";
    cout<<"DFS"<<"\n";
    g1.dfs();
    return 0;
}