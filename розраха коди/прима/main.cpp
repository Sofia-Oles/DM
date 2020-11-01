#include<iostream>
using namespace std;
int main()
{
    int a,b,u,v,n,i,j,ne=1;
    int visited[20]={0},min,mincost=0;
   int cost[20][20];
    int path[100]={0};
    int path_index=0;

    cout<<"Enter the number of vertices: ";
    cin>>n;
    cout<<"Enter the adjacency matrix: " << endl;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
        {
            cin>>cost[i][j];
            if(cost[i][j]==0)
                cost[i][j]=99;
        }
    }
    visited[1]=1;
    cout<<endl;;

    while(ne < n)
    {
        for(i=1,min=99;i<=n;i++)
            for(j=1;j<=n;j++)
                if(cost[i][j]< min)
                    if(visited[i]!=0)
                    {
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
        if(visited[u]==0 || visited[v]==0)
        {
            path[path_index]=b;
            path_index++;
            ne++;
            mincost+=min;
            visited[b]=1;
        }
        cost[a][b]=cost[b][a]=99;
    }
    cout<<endl;
    cout<<1<<" -> ";
    for (int i=0;i<n-1;i++)
    {
        cout<<path[i];
        if (i<n-2) cout<<" -> ";
    }
    cout<< endl << "The least way is: "<<mincost;
    cin.get();
    cin.get();
    return 0;
}
