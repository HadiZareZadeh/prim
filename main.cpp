#include <iostream>
using namespace std;


class graph
{
    public:
    int G[20][20],n,e;
    void accept();
    void prims();
    void display();
};

void graph::accept()
{
    int i,j;
    int cost,src,dest;
    cout << "enter number of vertices and edges: ";
    cin >> n >> e;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        {
            G[i][j]=0;
        }
    }

    for(i=0;i<e;i++){
        cout<<"\n enter src dest and cost:=";
        cin>>src>>dest>>cost;
        G[src][dest]=cost;
        G[dest][src]=cost;
    }
}

void graph::display()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<"\t"<<G[i][j];
        }
        cout<<"\n";
    }
}

void graph::prims()
{
    int i,j;
    int visited[20];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(G[i][j]==0)
                G[i][j]=9999;
        }
    }
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }
    int src,dest;
    cout << "enter the src for finding minimum spanning tree:= ";
    cin >> src;
    int total=0;
    visited[src]=1;
    int z=1;
    while(z<n)
    {
        int  min=9999;
        for(i=0;i<n;i++)
        {
            if(visited[i]==1)
            {
                for(j=0;j<n;j++)
                {
                    if(visited[j]!=1)
                    {
                        if(min>G[i][j])
                        {
                            min=G[i][j];
                            src=i;
                            dest=j;
                        }
                    }
                }
             }
        }
        visited[dest]=1;
        total=total+G[src][dest];
        cout << src << " -> " << dest << " cost:= " << min << "\n";
        z++;
    }
    cout << "total cost of minimum spanning tree:= " << total;
}

int main(){
    graph g;

    g.accept();
    g.display();
    g.prims();
    return 0;
}
