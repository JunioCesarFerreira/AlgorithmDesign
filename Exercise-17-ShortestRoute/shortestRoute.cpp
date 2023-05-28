#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<uint32_t, uint32_t> intPair;

class Graph 
{
    private:
        const uint64_t infinity = 18446744073709551615u;
        int num_vertices;
        vector<vector<intPair>> adj;

    public:
        Graph(int numVertices) 
        {
            num_vertices = numVertices;
            adj.resize(numVertices);
        }

        void addEdge(uint32_t u, uint32_t v, uint32_t weight) 
        {
            adj[u].push_back(make_pair(v, weight));
            adj[v].push_back(make_pair(u, weight));
        }

        vector<uint64_t> dijkstra(int start) 
        {
            vector<uint64_t> distance(num_vertices, infinity);

            priority_queue<intPair, vector<intPair>, greater<intPair>> pq;
            pq.push(make_pair(0, start));
            distance[start] = 0;

            while (!pq.empty()) 
            {
                int u = pq.top().second;
                uint64_t dist_u = pq.top().first;
                pq.pop();

                if (dist_u > distance[u])
                    continue;

                for (auto& edge : adj[u]) 
                {
                    int v = edge.first;
                    auto weight = edge.second;

                    if (distance[v] > distance[u] + weight) 
                    {
                        distance[v] = distance[u] + weight;
                        pq.push(make_pair(distance[v], v));
                    }
                }
            }

            return distance;
        }

        int64_t dist(intPair query)
        {
            vector<uint64_t> d = dijkstra(query.first);
            if (d[query.second] == infinity)
                return -1;
            else
                return d[query.second];
        }

        void printAdjList()
        {
	        for (int u = 0; u < num_vertices; ++u)
            {
		        printf("%d", u);
		        for (auto v : adj[u]) 
			        printf(" -> (%2d, %2d)", v.first, v.second);
		        printf("\n");
	        }
        }
};

int main(int argc, char const *argv[])
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
    
    vector<intPair> queries;
    for (int i=0; i<q; i++)
    {
        cin >> u >> v;
        queries.push_back(make_pair(u-1,v-1));
    }

#ifdef DEBUG

	graph.printAdjList(); 
    for (auto p : queries)
        printf("query: %d %d\n", p.first, p.second);

    for (auto query : queries)
    {
        vector<int> dist = graph.dijkstra(query.first);
        printf("dist(%d, %d) = %d\n", query.first, query.second, dist[query.second]);
        for (auto d : dist)
            printf("%d ", d);
        printf("\n");
    }

#else

    for (int i=0; i<q; i++)
        printf("%lld\n", graph.dist(queries[i]));
        
#endif

	return 0;
}

