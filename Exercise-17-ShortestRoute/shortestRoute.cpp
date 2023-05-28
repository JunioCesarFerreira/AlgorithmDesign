#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> intPair;

class Graph 
{
    private:
        const static int max_vertices = 500;
        const int64_t infinity = 9223372036854775807;//18446744073709551615u;
        int num_vertices;
        vector<intPair> adj[max_vertices];
        vector<vector<int64_t>> distance_vertices;

    public:
        Graph(int numVertices) 
        {
            num_vertices = numVertices;
            distance_vertices.resize(num_vertices);
        }

        void addEdge(int u, int v, int weight) 
        {
            // Verifica se a aresta já existe
            for (auto& edge : adj[u]) 
            {
                if (edge.first == v)
                {
                    if (edge.second > weight)
                    {
                        edge.second = weight;
                        for (auto& e : adj[v]) 
                            if (e.first == u)
                            {
                                e.second = weight;
                                break;
                            }
                    }
                    return; 
                }
            }
            adj[u].emplace_back(make_pair(v, weight));
            adj[v].emplace_back(make_pair(u, weight));
        }

        vector<int64_t> dijkstra(int start) 
        {
            vector<int64_t> distances(num_vertices, infinity);

            priority_queue<intPair, vector<intPair>, greater<intPair>> pq;
            pq.push(make_pair(0, start));
            distances[start] = 0;

            while (!pq.empty()) 
            {
                int u = pq.top().second;
                int64_t dist_u = pq.top().first;
                pq.pop();

                if (dist_u > distances[u]) continue;

                for (auto& edge : adj[u]) 
                {
                    int v = edge.first;
                    int weight = edge.second;
                    int64_t new_dist = distances[u] + weight;

                    if (distances[v] > new_dist) 
                    {
                        distances[v] = new_dist;
                        pq.push(make_pair(distances[v], v));
                    }
                }
            }

            return distances;
        }

        void preprocess()
        {
            for (int v=0; v < num_vertices; v++)
                distance_vertices[v] = dijkstra(v);
        }

        long long int dist(int u, int v)
        {
            if (distance_vertices[u][v]==infinity)
                return -1;
            else
                return distance_vertices[u][v];
        }
};

int main()
{
	int n, m, q;
    cin >> n >> m >> q;

    int u, v, w;
    Graph graph(n);
    for (int i=0; i<m; i++)
    {
        cin >> u >> v >> w;
        graph.addEdge(u-1, v-1, w);
	}
    
    graph.preprocess();

    for (int i=0; i<q; i++)
    {
        cin >> u >> v;
        printf("%lld\n", graph.dist(u-1,v-1));
    }

	return 0;
}