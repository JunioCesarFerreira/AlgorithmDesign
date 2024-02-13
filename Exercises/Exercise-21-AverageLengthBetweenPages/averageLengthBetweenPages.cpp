#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX_V 101

int adj[MAX_V][MAX_V];
bool on[MAX_V];

int main() 
{
	int u, v, count = 1;

	while (true) 
    {
		memset(adj, 63, sizeof adj);
		memset(on, false, sizeof on);

		scanf("%d %d", &u, &v);

		if (u == 0 && v == 0) break;

		while (true) 
        {
			on[u] = true;
			on[v] = true;
			adj[u][v] = 1;

			scanf("%d %d", &u, &v);
			if (u == 0 && v == 0) break;
		}

        // Floyd-Warshall algorithm
		for (int k = 0; k < MAX_V; k++)
			for (int i = 0; i < MAX_V; i++)
				for (int j = 0; j < MAX_V; j++)
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

		double sumDist = 0;
        double countPairs = 0;
		for (int i = 0; i < MAX_V; i++) 
        {
			for (int j = 0; j < MAX_V; j++) 
            {
				if (i == j) continue;

				if (on[i] && on[j]) 
                {
					sumDist += adj[i][j];
					countPairs++;
				}
			}
		}
        double avg = sumDist / countPairs;
		printf("Case %d: average length between pages = %.3lf clicks\n", count, avg);
        count++;
	}

	return 0;
}