#include <cstdio>
#include <vector>
#include <utility>
#include <bitset>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

#define INF   1e9
#define MAX_V 105 

using namespace std;

class EdmondsKarp
{
	private:
		vector<vector<int>> adj_list;  // Lista de adjacência do grafo de entrada
		int res_graph[MAX_V][MAX_V];   // Grafo residual utilizado pelo algoritmo
		vector<int> parents;           // Vetor auxiliar indicador de pais.

		int s;    // Origem.
		int t;    // Destino.
		int flow; // Fluxo.

		void augment(int v, int minEdge) 
		{
			if (v == s) 
    		{
				flow = minEdge;
			} 
    		else if (parents[v] != -1) 
    		{
				augment(parents[v], min(minEdge, res_graph[parents[v]][v]));
				res_graph[parents[v]][v] -= flow;
				res_graph[v][parents[v]] += flow;
			}
		}

	public:
		EdmondsKarp(int source, int target, int num_nodes)
		{
			memset(res_graph, 0, sizeof res_graph);	
			adj_list.assign(num_nodes, vector<int>());
			s = source;
			t = target;
		}

		void addEdge(int u, int v, int w)
		{
			res_graph[u][v] += w;
			res_graph[v][u] += w;
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}

		int maxFlow()
		{
			int max_flow = 0;
			do
    		{
				flow = 0;

				bitset<MAX_V> visited;
				visited.set(s);

				queue<int> q;
				q.push(s);

				parents.assign(MAX_V, -1);

				while (!q.empty()) 
        		{
					int u = q.front();
					q.pop();

					if (u == t) break;

					for (size_t i = 0; i < adj_list[u].size(); i++) 
            		{
						int v = adj_list[u][i];
						if (res_graph[u][v] > 0 && !visited.test(v)) 
                		{
							visited.set(v);
							q.push(v);
							parents[v] = u;
						}
					}
				}

				augment(t, INF);
				printf("flow = %d\n", flow);
				max_flow += flow;

			} while (flow != 0);

			return max_flow;
		}
};


int main() 
{
    int n, s, t, c;
    int count = 1;
	while (scanf("%d", &n), n) 
    {
		scanf("%d %d %d", &s, &t, &c);

		EdmondsKarp edmondsKarp = EdmondsKarp(s-1, t-1, n);

		for (int i = 0; i < c; i++) 
        {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			edmondsKarp.addEdge(u-1, v-1, w);
		}

		printf("Network %d\nThe bandwidth is %d.\n\n", count, edmondsKarp.maxFlow());
        count++;
	}

	return 0;
}