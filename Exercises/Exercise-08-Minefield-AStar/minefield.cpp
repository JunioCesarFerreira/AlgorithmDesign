#include <iostream>
#include <queue>

using namespace std;

//#define DEBUG_FIELD_VIEW
#define DEBUG_OPEN_NODES

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

struct Node 
{
    int x, y, length;
};

int x_size, y_size;               // tamanho do campo minado
int field[MAX_ROWS][MAX_COLS];    // campo minado
bool visited[MAX_ROWS][MAX_COLS]; // células visitadas durante a BFS

int dx[] = {0, 1, -1, 0}; // deslocamento em x para os 4 vizinhos
int dy[] = {1, 0, 0, -1}; // deslocamento em y para os 4 vizinhos


bool isField(int x, int y)
{
    return x >= 0 && x < x_size &&  y >= 0 && y < y_size;
}

bool isSafe(int x, int y)
{
    if (field[x][y] == 0) return false;

    for (int i=0; i<4; i++)
    {
        if (isField(x + dx[i], y + dy[i]))
        {
            if (field[x + dx[i]][y + dy[i]] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

int bfs(int start_x, int start_y) 
{
    if (!isSafe(start_x, start_y)) return -1;

    queue<Node> q;
    q.push({start_x, start_y, 0});
    visited[start_x][start_y] = true;

    while (!q.empty()) 
    {
        Node current = q.front();
        q.pop();

        if (current.y == y_size-1)
        {
#ifdef DEBUG_OPEN_NODES
            cout << "path length = " << current.length << endl;
            for (int i = 0; i < x_size; i++) 
            {
                for (int j = 0; j < y_size; j++) 
                {                
                    visited[i][j] ? cout << "O " : (field[i][j]==0 ?  cout << "X " : cout << ". ");
                }
                cout << endl;
            }
            cout << endl;
#endif
            return current.length;
        }

        for (int i = 0; i < 4; i++) 
        {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (isSafe(nx, ny) && !visited[nx][ny]) 
            {
                visited[nx][ny] = true;
                q.push({nx, ny, current.length + 1});
            }
        }
    }

    return -1; // destino não encontrado
}

int main() 
{
    cin >> x_size >> y_size;

    for (int i = 0; i < x_size; i++) 
        for (int j = 0; j < y_size; j++) 
            cin >> field[i][j];

#ifdef DEBUG_FIELD_VIEW
    cout << endl;
    for (int row=0; row < x_size; row++)
    {
        for (int col=0; col < y_size; col++)
        {
            isSafe(row, col, x_size, y_size) ? cout << ". " : cout << "X ";
        }
        cout << endl;
    }
    cout << endl;
#endif 

    clock_t start_time = clock();
    int min_length = -1;
    for (int x=0; x < x_size; x++)
    {
        for (int i = 0; i < x_size; i++) 
            for (int j = 0; j < y_size; j++) 
                visited[i][j] = false;

        int tmp_length = bfs(x, 0);

        if (tmp_length != -1 && (min_length == -1 || tmp_length < min_length))
                min_length = tmp_length;
    }
    clock_t end_time = clock();
    double interval = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    if (min_length == -1)
        cout << "Nao ha caminho valido" << endl;
    else 
        cout << "Comprimento da rota = " << min_length << endl;

    cout << "runtime: " << interval << " s\n";
    return 0;
}