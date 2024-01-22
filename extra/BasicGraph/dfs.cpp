#include <iostream>
#include <vector>

using namespace std;

void dfs(int vertex, const vector<vector<int>>& graph, vector<bool>& visited) 
{
    visited[vertex] = true;
    cout << "vertice " << vertex << endl;

    for (int neighbor : graph[vertex]) 
    {
        if (!visited[neighbor]) 
            dfs(neighbor, graph, visited);
    }
}

void depthFirstSearch(const vector<vector<int>>& graph) 
{
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);

    for (int i = 0; i < numVertices; i++) 
    {
        if (!visited[i])
            dfs(i, graph, visited);
    }
}

int main() 
{
    // lista de adjacência do grafo
    vector<vector<int>> graph = 
    {
        {1, 2},     
        {0, 2, 3},  
        {0, 1, 3, 5},  
        {1, 2, 4},  
        {3},
        {2}         
    };

    depthFirstSearch(graph);

    return 0;
}