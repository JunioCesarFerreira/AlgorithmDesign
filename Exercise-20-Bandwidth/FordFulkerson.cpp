#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

#define N 4

using namespace std;

int graph[N][N] = 
{
    {0,20,10,0},
    {0,0,5,10},
    {0,3,0,20},
    {0,0,0,0}
};

int residualGraph[N][N];
int parent[N];

bool hasPath(int source, int target)
{
    queue<int> q;

    q.push(source);
    parent[source] = -1;

    int visited[N];
    memset(visited, 0, sizeof visited);
    visited[source] = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < N; ++v)
        {
            if (residualGraph[u][v] > 0 && visited[v] == 0) 
            {
                q.push(v);
                parent[v] = u;
                visited[v] = 1;
            }
        }
    }

    return (visited[target] == 1);
}

int fordFulkerson()
{
    memcpy(residualGraph, graph, sizeof graph);

    int source = 0;
    int target = 3;

    int maxFlow = 0;

    while (hasPath(source, target))
    {
        int bottleneck = 100000;

        for (int v = target; v != source; v = parent[v])
        {
            int u = parent[v];
            bottleneck = min(bottleneck, residualGraph[u][v]);
        }

        for (int v = target; v != source; v = parent[v])
        {
            int u = parent[v];
            residualGraph[u][v] -= bottleneck;
            residualGraph[v][u] += bottleneck;
        }

        maxFlow += bottleneck;
    }

    return maxFlow;
}

int main(int argc, char const *argv[])
{
    printf("The maximum flow in the graph is %d\n", fordFulkerson());
    return 0;
}
