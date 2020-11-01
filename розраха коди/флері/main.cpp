#include <iostream>
using namespace std;
#define N 12
#define STACK_SIZE 100
int G[N][N] =
{
    {0,0,0,1,0,0,0,1,1,0,0,1},
    {0,0,1,0,0,0,0,0,0,0,0,1},
    {0,1,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,1,1,1,0,0,0,1,1},
    {0,0,0,1,0,1,0,0,0,0,1,1},
    {0,0,0,1,1,0,1,0,0,0,1,0},
    {0,0,0,1,0,1,0,1,0,0,1,0},
    {1,0,0,0,0,0,1,0,1,1,0,0},
    {1,0,0,0,0,0,0,1,0,1,0,1},
    {0,0,0,0,0,0,0,1,1,0,1,1},
    {0,0,0,1,1,1,1,0,0,1,0,1},
    {1,1,1,1,1,0,0,0,1,1,1,0}};

int k;
int Stack[STACK_SIZE];

void Search(int V)
{
    int i;
    for(i = 0; i < N; i++)
        if(G[V][i])
        {
            G[V][i] = G[i][V] = 0;
            Search(i);
        }
    Stack[++k] = V;
}

int main()
{
    int T, p, q, s;
    int j, vv;

    T = 1;
    for(p = 0; p < N; p++)
    {
        s = 0;
        for(q = 0; q < N; q++)
        {
            s += G[p][q];
        }
        if(s%2) T = 0;}
    k = -1;
cout<<"start vertex: ";
cin>>vv;
vv--;
if(T)
    {
        Search (vv);
    for(j = 0; j <= k; j++)
            cout<<Stack[j]+1<<" ";}
else
cout<<"not Eulerian graph\n";
return 0;
}
