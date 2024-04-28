#include <iostream>

using namespace std;

void BFS(int** graph, int numCities, int source) 
{
    bool* visited = new bool[numCities];
    for (int i = 0; i < numCities; i++) 
		{
        visited[i] = false;
    }

    int* queue = new int[numCities];
    int front = -1;  
    int rear = -1;   

    visited[source] = true;
    queue[++rear] = source;

    while (front != rear) 
			{
        int currentCity = queue[++front];
        cout << currentCity << " ";

        for (int i = 0; i < numCities; i++) 
						{
	            if (graph[currentCity][i] == 1 && !visited[i]) 
							{
                visited[i] = true;
                queue[++rear] = i;
	            }
		        }
			}

    delete[] visited;
    delete[] queue;
}

int main() 
{
    int numCities, numConnections;
    cin >> numCities >> numConnections;

    int** graph = new int*[numCities];
    for (int i = 0; i < numCities; i++) 
		{
        graph[i] = new int[numCities];
        for (int j = 0; j < numCities; j++) 
				{
            graph[i][j] = 0;
        }
	  }

    for (int i = 0; i < numConnections; i++) 
		{
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
    }
		
    int source;
    cin >> source;

    BFS(graph, numCities, source);

    for (int i = 0; i < numCities; i++) 
		{
        delete[] graph[i];
    }

    delete[] graph;

    return 0;
}

/*SAMPLE INPUT
6 7
0 1
0 2
1 3
1 4
2 4
3 5
4 5
0
SAMPLE OUTPUT
0 1 2 3 4 5 
*/