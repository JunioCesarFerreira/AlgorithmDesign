#include <iostream>
#include <vector>

using namespace std;

bool colorGraph(int v, vector<vector<int>>& graph, vector<int>& colors, int color) 
{
    colors[v] = color;

    for (int neighbor : graph[v]) 
    {
        if (colors[neighbor] == color)
            return false;

        if (colors[neighbor] == 0 && !colorGraph(neighbor, graph, colors, 3 - color))
            return false;
    }

    return true;
}

void buildTeams(int n, int m, vector<vector<int>>& friendships) 
{
    vector<vector<int>> graph(n + 1);
    vector<int> colors(n + 1, 0);

    for (int i = 0; i < m; i++) 
    {
        int a = friendships[i][0];
        int b = friendships[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) 
    {
        if (colors[i] == 0 && !colorGraph(i, graph, colors, 1)) 
        {
            printf("IMPOSSIBLE\n");
            return;
        }
    }

    for (int i = 1; i <= n; i++) 
        printf("%d ", colors[i]);
}

int main() 
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> friendships(m, vector<int>(2));
    for (int i = 0; i < m; i++) 
        cin >> friendships[i][0] >> friendships[i][1];

    buildTeams(n, m, friendships);

    return 0;
}