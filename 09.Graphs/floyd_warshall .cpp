#include <iostream>

using namespace std;

const int INF = 1e9;


int main()
{
    int v, e;
    cin>>v>>e;

    int g[v][v];

    for(int i = 0 ; i < v ; i++)
        {
            for(int j = 0 ; j< v ; j++)
                {
                   g[i][j] = 0;
                }
        }

    int v1 , v2 , w;
    for(int i = 0 ;i< e ; i++)
        {
            cin>>v1>>v2>>w;
            g[v1-1][v2-1] = w;
        }

    cout<<"the weighted graph representation using matrix :- "<<endl; 
     for(int i = 0 ;i< v ; i++)
        {
           for(int j = 0 ;j < v ; j++)
               {
                   cout<<g[i][j]<<" ";
               }
            cout<<endl;
        }

    int dist[v][v];
    
    for(int i = 0 ; i< v ; i++)
        {
            for(int j = 0 ; j< v ; j++)
                {
                    if(g[i][j] != 0)
                        dist[i][j] = g[i][j];
                    else
                        dist[i][j] = INF;
                }
        }

    for(int k = 1; k<= v ; k++)
        {
            for(int i = 1 ; i<= v ; i++)
                {
                    for(int j = 1; j<= v ;j++)
                        {
                            if(dist[i][k] != INF && dist[k][j] != INF)
                                dist[i][j] = min(dist[i][j], dist[i][k]+ dist[k][k]);
                        }
                }
        }


    //printing the distance array
    cout<<"the shortest distance matrix :- "<<endl;
    
    for(int i = 0 ;i< v ; i++)
        {
            for(int  j = 0 ; j< v ;j++)
                {
                    if(dist[i][j] == INF)
                    {
                        cout<<"I"<<" ";
                    }
                    else
                        cout<<dist[i][j]<<" ";
                }cout<<endl;
        }cout<<endl;

    
}

/* SAMPLE INPUT
6 9
1 2 1
1 3 5
2 3 2
3 5 3
2 5 1
2 4 2
4 5 3
4 6 1
5 6 2
*/