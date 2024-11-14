#include <vector>
using namespace std;
vector<int> graph[250001];
int maxV, maxDist;

void DFS(int n, int prev, int dist, int banned) {
    if (maxDist < dist) {
        maxDist = dist;
        maxV = n;
    }
    for (auto c : graph[n])
        if (c != prev && c != banned)
            DFS(c, n, dist + 1, banned);
}

int solution(int n, vector<vector<int>> edges) {
    for (auto edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    maxDist = -1; DFS(1, 0, 0, -1); int A = maxV;
    maxDist = -1; DFS(A, 0, 0, -1); int B = maxV;
    maxDist = -1; DFS(A, 0, 0, B); int dist1 = maxDist;
    maxDist = -1; DFS(B, 0, 0, A); int dist2 = maxDist;
    return max(dist1, dist2);
}
