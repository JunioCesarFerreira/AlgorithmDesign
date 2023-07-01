#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1000;
vector<int> adjList[MAXN];
int dist[MAXN], sigma[MAXN], delta[MAXN];
bool inStack[MAXN];
stack<int> S;

void dfs(int v, int& index, vector<int>& ids, vector<int>& low) 
{
    ids[v] = low[v] = ++index;
    S.push(v);
    inStack[v] = true;
    for (int i = 0; i < adjList[v].size(); i++) 
    {
        int w = adjList[v][i];
        if (ids[w] == 0) 
        {
            dfs(w, index, ids, low);
            low[v] = min(low[v], low[w]);
        } 
        else if (inStack[w]) 
        {
            low[v] = min(low[v], ids[w]);
        }
    }
    if (ids[v] == low[v]) 
    {
        while (true) 
        {
            int w = S.top();
            S.pop();
            inStack[w] = false;
            if (w == v) break;
        }
    }
}

void computeBC(int s, int N) 
{
    vector<int> ids(N, 0), low(N, 0);
    int index = 0;
    dfs(s, index, ids, low);
    fill(delta, delta+N, 0);
    while (!S.empty()) S.pop();
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < adjList[i].size(); j++) 
        {
            int w = adjList[i][j];
            if (low[i] < low[w]) 
            {
                delta[w] += (sigma[w] * (1.0 + delta[i])) / sigma[i];
            }
        }
        if (i != s) 
        {
            cout << "BC(" << i << "): " << delta[i] << endl;
        }
    }
}

int main() 
{
    int N = 6, M = 7;
    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[1].push_back(2);
    adjList[1].push_back(4);
    adjList[2].push_back(3);
    adjList[3].push_back(4);
    adjList[4].push_back(5);
    adjList[5].push_back(3);
    for (int i = 0; i < N; i++) sigma[i] = 1;
    for (int i = 0; i < N; i++) inStack[i] = false;
    computeBC(0, N);
    return 0;
}
/*
Nesta implementação, a função dfs implementa uma busca em profundidade para identificar componentes fortemente conectados no grafo. A função computeBC implementa o cálculo da centralidade de intermediários usando a fórmula de Brandes.

O programa de exemplo cria um grafo de teste com 6 vértices e 7 arestas, e em seguida calcula a centralidade de intermediários a partir do vértice 0. O resultado é exibido na saída padrão.

Observe que essa implementação é apenas um exemplo e pode ser modificada para atender às necessidades do problema em questão.
*/