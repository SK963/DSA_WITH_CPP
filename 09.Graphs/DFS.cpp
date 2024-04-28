//PARTIALLY CORREC CODE 
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e3;
bool vis[N] = {false};

vector<int>graph[N]; // list for max 10^3 nodes with weight

void dfs(vector<int> graph[] ,int vertex)
{
    //checking the working
    cout<<"vertex :- "<<vertex<<endl;
    //  take action on vertex after entering the vertex
    // if(vis[vertex] == true) return; this line checks as same as the  (if(vis[child] == true) continue)
    vis[vertex] = true;

    for(int child :graph[vertex])
        {
            //take action on child before entering the child node - printing the process
            cout<<"parent: "<<vertex <<" "<<"child: "<<child<<endl;

            
            if(vis[child] == true) continue;
            
            dfs(graph , child);  // recursively traverse every node
            // take action on child after exiting the child 
        }
    // take action on vertex before exiting 
    
}




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

int main()
{
    int n, m; // n vertices and m edges
    cin >> n >> m;

    
   

    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1); // this line will be commented for directed graph
    }

    // print(graph , n );
    dfs(graph , 1);
    

    
    return 0;
}

/* SAMPLE INPUT
6 9
1 3
1 5
3 5
3 4
3 6
3 2
2 6
4 6
5 6

OUTPUT
vertex :- 1
parent: 1 child: 3
vertex :- 3
parent: 3 child: 1
parent: 3 child: 5
vertex :- 5
parent: 5 child: 3
parent: 5 child: 6
vertex :- 6
parent: 6 child: 3
parent: 6 child: 2
vertex :- 2
parent: 2 child: 6
parent: 6 child: 5
parent: 6 child: 5
parent: 6 child: 5
parent: 6 child: 5
parent: 5 child: 6
parent: 5 child: 6
parent: 5 child: 6
parent: 3 child: 4
vertex :- 4
parent: 4 child: 3
parent: 3 child: 6

*/