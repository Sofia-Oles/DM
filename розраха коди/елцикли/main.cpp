#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <list>
using namespace std;

vector < list<int> > graph;
vector <int> deg;
stack<int> head, tail;
int main()
{
//deg is the degree of a given vertex
  int n, a, x, y;
  cout<<"Enter count of tops / edges: ";
  cin >> n >> a; //12 26
  graph.resize(n + 1);
  deg.resize(n + 1);
  for (; a--;)
  {
    cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
    ++deg[x];
    ++deg[y];
  }

if (any_of(deg.begin() + 1, deg.end(), [](int i) {return i & 1; }))
cout << "-1";           /*< no euler cycle exists (all degrees must be even) */

  else
  {
    head.push(1);
    while (!head.empty())
    {
      while (deg[head.top()])
      {
        int v = graph[head.top()].back();
        graph[head.top()].pop_back();
        graph[v].remove(head.top());
        --deg[head.top()];
        head.push(v);
        --deg[v]; }

      while (!head.empty() && !deg[head.top()])
      {
        tail.push(head.top());
        head.pop(); }
    }
    /*< tail is the eulerian cycle */
    while (!tail.empty())
    {
      cout << tail.top() << ' ';
      tail.pop();
    } } }
