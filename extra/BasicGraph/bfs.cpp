#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void breadthFirstSearch(const vector<vector<int>>& graph) 
{
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    queue<int> queue;

    for (int startVertex = 0; startVertex < numVertices; startVertex++) 
    {
        if (visited[startVertex])
            continue;

        visited[startVertex] = true;
        queue.push(startVertex);

        while (!queue.empty()) 
        {
            int vertex = queue.front();
            queue.pop();
            cout << "vertice " << vertex << endl;

            for (int neighbor : graph[vertex]) 
            {
                if (!visited[neighbor]) 
                {
                    visited[neighbor] = true;
                    queue.push(neighbor);
                }
            }
        }
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

    breadthFirstSearch(graph);

    return 0;
}