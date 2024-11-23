#include <vector>
#include <queue>
#include <cmath>
using namespace std;
struct Edge { int x, y, w; };
vector<vector<int>> L;
int N, M, H, genID = 1, area[301][301], dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
vector<Edge> graph[90001];
bool visited[90001];
struct cmp { bool operator()(Edge a, Edge b) { return a.w > b.w; } };
priority_queue<Edge, vector<Edge>, cmp> pq;

void DFS(int x, int y) {
    if(area[y][x] > 0) return;
    area[y][x] = genID;
    for(int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if(nx < 0 || nx >= M || ny < 0 || ny >= N)
            continue;
        int cost = abs(L[y][x] - L[ny][nx]);
        if(cost <= H)
            DFS(nx, ny);
        else
            graph[genID].push_back({ nx, ny, cost });
    }
}

void addEdge(int v) {
	for (auto next : graph[v])
		if (!visited[area[next.y][next.x]])
            pq.push(next);
}

int mst() {
    int cost = 0;
	addEdge(1); visited[1] = 1;
	while (!pq.empty()) {
		Edge next = pq.top(); pq.pop();
        int v = area[next.y][next.x];
		if (visited[v])
            continue;
        visited[v] = 1;
		cost += next.w;
		addEdge(v);
	}
    return cost;
}

int solution(vector<vector<int>> land, int height) {
    L = land, N = land.size(), M = land[0].size(), H = height;
    for(int y = 0; y < N; y++)
        for(int x = 0; x < M; x++)
            if(area[y][x] == 0)
                DFS(x, y), genID++;
    return mst();
}
