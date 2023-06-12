#include <iostream>
#include <cstring>
#include <queue>

#define N 101

using namespace std;

int graph[N][N];
int residualGraph[N][N];
int parent[N];
int visited[N];

void printAdjMatrix(int g[N][N], int n)
{
    printf("\n");
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            printf("%2d\t", g[i][j]);
        printf("\n");
    }
}

bool hasPath(int source, int target, int numberNodes)
{
    queue<int> q;

    q.push(source);
    parent[source] = -1;

    memset(visited, 0, sizeof visited);
    visited[source] = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < numberNodes; ++v)
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

int fordFulkerson(int source, int target, int numberNodes)
{
    memcpy(residualGraph, graph, sizeof graph);

    int maxFlow = 0;

    while (hasPath(source, target, numberNodes))
    {
        int bottleneck = 100001;

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

int main() 
{
    int networkCount = 1;
    int n;

    while (cin >> n && n != 0) 
    {
        int s, t, c;
        cin >> s >> t >> c;
        memset(graph, 0, sizeof graph);

        for (int i = 0; i < c; i++) 
        {
            int v1, v2, bandwidth;
            cin >> v1 >> v2 >> bandwidth;
            v1--; v2--;
            graph[v1][v2] = graph[v1][v2]==0 ? bandwidth : graph[v1][v2]+bandwidth;
        }

        // Cálculo da largura de banda total entre os nós de origem e destino
        int totalBandwidth = fordFulkerson(s-1, t-1, n);

        // Impressão dos resultados
        cout << "Network " << networkCount << "\n";
        cout << "The bandwidth is " << totalBandwidth << "\n\n";

        networkCount++;
    }

    return 0;
}
