//BFS TRAVERSAL IN A TREE
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e5;
bool vis[N] = {false};
int level[N];

vector<int>graph[N]; 

void print(vector <int> graph[] , int n)
{
     cout << "the adj. list representation:- " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Node " << i+1 << ": ";
        for (auto p : graph[i])
        {
            cout << p<<" ";
        }
        cout << endl;
    }
}
void bfs(int source)
{
    queue<int >q;
    q.push(source);
    vis[source] = true;
    cout<<"the bsf traversal :- ";
    while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            cout<<cur<<" ";
            for(int child: graph[cur])
                {
                    if(!vis[child])
                    {
                        q.push(child);
                        vis[child] == true;
                        level[child] = level[cur] +1;
                    }
                }
        }cout<<endl;
}

int main()
{
    int n; // n vertices and m edges
    cin >> n;
    
    for (int i = 0; i < n-1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1); // this line will be commented for directed graph
    }

    bfs(1);
    //printing the level

    for(int i = 0 ; i< n ; i++)
        {
            cout<<i<<":"<<level[i] <<endl;
        }
    

    
    return 0;
}
/*INPUT
13
1 2
1 3
1 13
2 5
5 6
5 7
5 8
8 12
3 4
4 9
4 10
10 11
9 11
    */
