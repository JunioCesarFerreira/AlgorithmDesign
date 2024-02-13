#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estrutura para representar uma rodovia
struct Road 
{
    int source;
    int destiny;
    long cost;
};

// Estrutura para representar um subconjunto (conjunto de cidades)
struct Subset 
{
    int parent;
    int rank;
};

// Função para encontrar o conjunto de uma cidade usando a técnica Union-Find
int find(Subset subsets[], int i) 
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// Função para unir dois conjuntos em um único conjunto
void Union(Subset subsets[], int x, int y) 
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;

    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    else 
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Função para comparar rodovias com base no custo
bool compareCost(const Road& a, const Road& b) 
{
    return a.cost < b.cost;
}

// Função principal para encontrar a MST usando o algoritmo de Kruskal
vector<Road> findMinimumSpanningTree(int n, int m, vector<Road>& roads) 
{
    vector<Road> mst;

    // Ordena rodovias por custo crescente
    sort(roads.begin(), roads.end(), compareCost); 

    Subset* subsets = new Subset[n];
    for (int i = 0; i < n; i++) 
    {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int edgeCount = 0;
    for (int i = 0; edgeCount < n - 1 && i < m; i++) 
    {
        int x = find(subsets, roads[i].source);
        int y = find(subsets, roads[i].destiny);
        if (x != y) 
        {
            mst.push_back(roads[i]);
            Union(subsets, x, y);
            edgeCount++;
        }
    }

    delete[] subsets;
    return mst;
}

int main() 
{
    int n, m;
    int src, dst;
    long long cst;
    cin >> n >> m;

    vector<Road> roads(m);
    for (int i=0; i<m; i++)
    {
        cin >> src >> dst >> cst;
        roads[i].source = src-1;
        roads[i].destiny = dst-1;
        roads[i].cost = cst;
	}

    //for (const auto& road : roads)
    //    printf("%2d -[%2d]-> %2d\n", road.src, road.dest, road.cost);

    vector<Road> mst = findMinimumSpanningTree(n, m, roads);
    if (mst.size() == (size_t)(n-1))
    {
        long long total = 0;
        for (auto& e : mst) total += e.cost;
        printf("%lld", total);
    }
    else
        printf("IMPOSSIBLE");
    
    return 0;
}