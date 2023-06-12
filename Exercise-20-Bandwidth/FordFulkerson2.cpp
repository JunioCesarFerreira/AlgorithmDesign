#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Estrutura de dados para representar uma aresta
struct Edge 
{
    int v;          // Vértice de destino
    int capacity;   // Capacidade da aresta
    int flow;       // Fluxo atual da aresta
};

// Função auxiliar para adicionar uma aresta ao grafo
void addEdge(vector<vector<Edge>>& graph, int u, int v, int capacity)
{
    Edge e1 = {v, capacity, 0};
    Edge e2 = {u, 0, 0};
    graph[u].push_back(e1);
    graph[v].push_back(e2);
}

// Função para encontrar um caminho aumentante usando busca em largura (BFS)
bool bfs(vector<vector<Edge>>& graph, int source, int sink, vector<int>& parent) 
{
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()) 
    {
        int u = q.front();
        q.pop();

        for (const Edge& e : graph[u]) 
        {
            int v = e.v;
            if (!visited[v] && e.capacity > e.flow) 
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[sink];
}

// Função principal do algoritmo de Ford-Fulkerson
int fordFulkerson(vector<vector<Edge>>& graph, int source, int sink) 
{
    int n = graph.size();
    vector<int> parent(n);
    int maxFlow = 0;

    while (bfs(graph, source, sink, parent)) 
    {
        int pathFlow = numeric_limits<int>::max();

        // Encontra a capacidade residual mínima ao longo do caminho
        for (int v = sink; v != source; v = parent[v]) 
        {
            int u = parent[v];
            for (Edge& e : graph[u]) 
            {
                if (e.v == v) 
                {
                    int residual = e.capacity - e.flow;
                    pathFlow = min(pathFlow, residual);
                    break;
                }
            }
        }

        // Atualiza os fluxos das arestas ao longo do caminho
        for (int v = sink; v != source; v = parent[v]) 
        {
            int u = parent[v];
            for (Edge& e : graph[u]) 
            {
                if (e.v == v) 
                {
                    e.flow += pathFlow;
                    break;
                }
            }
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() 
{
    int numVertices = 4;
    int source = 0;
    int sink = 3;

    // Criação do grafo
    vector<vector<Edge>> graph(numVertices);

    // Adiciona as arestas do grafo
    addEdge(graph, 0, 1, 20);
    addEdge(graph, 0, 2, 10);
    addEdge(graph, 1, 2, 5);
    addEdge(graph, 2, 1, 3);
    addEdge(graph, 1, 3, 10);
    addEdge(graph, 2, 3, 20);

    int maxFlow = fordFulkerson(graph, source, sink);
    cout << "Fluxo máximo: " << maxFlow << endl;

    return 0;
}
