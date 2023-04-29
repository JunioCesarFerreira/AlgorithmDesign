#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <map>

using namespace std;

const int N = 3; // Dimensão do jogo

typedef vector<int> vi;

vi final = { 1, 2, 3, 4, 5, 6, 7, 8, 0 };

int find_pos(vi s, int empty)
{
	for (int i = 0; i < (int)s.size(); ++i)
		if (s[i] == empty)
			return i;
	return -1;
}

void next_states(vi s, int &n, vi next[4], char *m)
{
	int pos = find_pos(s, 0); // encontra a posicao do zero...
	int lin = pos/3;  
	int col = pos%3;
	
	next[0] = next[1] = next[2] = next[3] = s;
	
	if (lin == 0 && col == 0)
	{
		n = 2;
		swap(next[0][lin*N+col], next[0][lin*N+col+1]); m[0] = 'r'; // troca colunas
		swap(next[1][lin*N+col], next[1][(lin+1)*N+col]); m[1] = 'd'; // troca linhas
	} 
	else if (lin == 0 && col == 2)
	{
		n = 2;
		swap(next[0][lin*N+col], next[0][lin*N+col-1]); m[0] = 'l'; // troca colunas
		swap(next[1][lin*N+col], next[1][(lin+1)*N+col]); m[1] = 'd'; // troca linhas
	} 
	else if (lin == 2 && col == 0)
	{
		n = 2;
		swap(next[0][lin*N+col], next[0][lin*N+col+1]); m[0] = 'r';// troca colunas
		swap(next[1][lin*N+col], next[1][(lin-1)*N+col]); m[1] = 'u';// troca linhas
	}  
	else if (lin == 2 && col == 2)
	{
		n = 2;
		swap(next[0][lin*N+col], next[0][lin*N+col-1]); m[0] = 'l';// troca colunas
		swap(next[1][lin*N+col], next[1][(lin-1)*N+col]); m[1] = 'u';// troca linhas
	} 
	else if (lin == 0 && col == 1)
	{
		n = 3;
		swap(next[0][lin*N+col], next[0][lin*N+col-1]); m[0] = 'l';// troca colunas
		swap(next[1][lin*N+col], next[1][lin*N+col+1]); m[1] = 'r';// troca colunas
		swap(next[2][lin*N+col], next[2][(lin+1)*N+col]); m[2] = 'd';// troca linhas
	} 
	else if (lin == 2 && col == 1)
	{
		n = 3;
		swap(next[0][lin*N+col], next[0][lin*N+col-1]); m[0] = 'l';// troca colunas
		swap(next[1][lin*N+col], next[1][lin*N+col+1]); m[1] = 'r';// troca colunas
		swap(next[2][lin*N+col], next[2][(lin-1)*N+col]); m[2] = 'u';// troca linhas
	} 
	else if (lin == 1 && col == 0)
	{
		n = 3;
		swap(next[0][lin*N+col], next[0][lin*N+col+1]); m[0] = 'r';// troca coluna
		swap(next[1][lin*N+col], next[1][(lin-1)*N+col]); m[1] = 'u';// troca linha
		swap(next[2][lin*N+col], next[2][(lin+1)*N+col]); m[2] = 'd';// troca linha
	} 
	else if (lin == 1 && col == 2)
	{
		n = 3;
		swap(next[0][lin*N+col], next[0][lin*N+col-1]); m[0] = 'l';// troca coluna
		swap(next[1][lin*N+col], next[1][(lin-1)*N+col]); m[1] = 'u';// troca linha
		swap(next[2][lin*N+col], next[2][(lin+1)*N+col]); m[2] = 'd';// troca linha
	} 
	else 
	{  // 0 está no centro do tabuleiro.. troca os 4....
		n = 4;
		swap(next[0][lin*N+col], next[0][lin*N+col-1]); m[0] = 'l';// troca coluna
		swap(next[1][lin*N+col], next[1][lin*N+col+1]); m[1] = 'r';// troca coluna
		swap(next[2][lin*N+col], next[2][(lin-1)*N+col]); m[2] = 'u';// troca linha
		swap(next[3][lin*N+col], next[3][(lin+1)*N+col]); m[3] = 'd';// troca linha
	}
}

bool equal(vi s, vi f)
{
	for (int i = 0; i < N*N; ++i)
		if (s[i] != f[i])
			return false;

	return true;
}

string bfs(vi s)
{
	vi next[4];
	queue<vi> q;   // fila simples....
	map<vi,string> visitado;
	char moves[4];
	int qtd;

	// coloca o estado inicial na fila
	q.push(s);
	// marca o estado inicial como visitado que nao tem movimento nenhum
	visitado[s] = "";

	while(!q.empty())
	{
		vi atual = q.front(); 
		q.pop();
		// opa... final.... imprime a sequencia de movimentos
		if (equal(atual,final))
			return visitado[atual];

		// nao é igual.. entao, calcula todos os proximos estados e continua a busca em largura.....
		next_states(atual, qtd, next, moves);
		for (int i=0; i<qtd; i++)
			if (!visitado.count(next[i]))
			{  // estado nao esta no mapa
				visitado[next[i]] = visitado[atual] + moves[i];
				q.push(next[i]);
			}
	}
	return "no solution";
}


int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--) 
	{
		vi s;  // source state...
		char k;
		for (int i = 0; i < 9; i++) 
		{
			cin >> k;
			if (k == 'x')  k = '0';
		 	s.push_back(k-'0');
		}
		cout << bfs(s) << endl;
		if (t > 0) cout << endl;
	}
	return 0;
}
