#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

// par de inteiros: guarda o vertice v e o peso da aresta
typedef pair<int,int> ii;

// todos os vertices v adjacentes a u 
typedef vector<ii> vii;

// lista de adjacencia para todo vertice u do meu grafo..
vector<vii> adj_list(200);

typedef vector<int> vi;

#define VISITADO 1
#define NAOVISITADO 0


int nv;

vi vis;


void printAdjList(){
	for (int u = 0; u < nv; ++u){ // para todo vertice u
		printf("%d -> ", u);
		for (int i = 0; i < adj_list[u].size(); ++i) { // para todo adjacente v de u
			ii v = adj_list[u][i];
			printf("(%d, %d) -> ", v.first, v.second);
		}
		printf("\n");
	}
}

void dfs(int u){
	printf("%d ", u+1);
	vis[u] = VISITADO;

	for (int i = 0; i < adj_list[u].size(); ++i) { // para todo adjacente v de u
		ii v = adj_list[u][i];
		if (vis[v.first] == NAOVISITADO)
			dfs(v.first);
	}

}

void cc(){
	int qtd = 0;
	for (int i = 0; i < nv; ++i) { //para todos os vertices do grafo
		if (vis[i] == NAOVISITADO){
			printf("%d : ", ++qtd); 
			dfs(i);
			printf("\n");
		}
	}
}


int main(int argc, char const *argv[])
{
	cin >> nv;
	int u,v;

	vis.assign(nv, NAOVISITADO);  // inicio vetor de visitados livre...

	while (cin >> u >> v){  // leia todas as arestas..
		// porque o grafo eh nao direcionado...
		adj_list[u-1].push_back(make_pair(v-1, 0));
		adj_list[v-1].push_back(make_pair(u-1, 0));
	}

	//printAdjList();

	cc();

	return 0;
}

