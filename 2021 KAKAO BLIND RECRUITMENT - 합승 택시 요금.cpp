#include <vector>
using namespace std;
const int INF = 20000001;
int N, cost = INF, adj[201][201];

void floyd() {
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    N = n;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (i != j)
                adj[i][j] = INF;
    for (auto edge : fares) {
        adj[edge[0]][edge[1]] = edge[2];
        adj[edge[1]][edge[0]] = edge[2];
    }
    floyd();
    for (int i = 1; i <= N; i++)
        cost = min(cost, adj[s][i] + adj[i][a] + adj[i][b]);
    return cost;
}
