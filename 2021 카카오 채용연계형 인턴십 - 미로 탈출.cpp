#include <vector>
#include <queue>
using namespace std;
struct Node { int v, t, w; };
struct cmp { bool operator()(Node& a, Node& b) { return a.w > b.w; } };
int N, dist[1001][1 << 10], graph[1001][1001];
vector<int> traps(1001, -1);
priority_queue<Node, vector<Node>, cmp> pq;
const int INF = 1e9;

int Dijkstra(int S, int E) {
    for (int j = 0; j < 1 << 10; j++)
        for (int i = 1; i <= N; i++)
            dist[i][j] = INF;
    dist[S][0] = 0; pq.push({ S, 0, 0 });
    while (!pq.empty()) {
        Node node = pq.top(); pq.pop();
        int v = node.v, t = node.t;
        bool myInv = traps[v] != -1 && t & (1 << traps[v]);
        for (int nv = 1; nv <= N; nv++) {
            bool nextInv = traps[nv] != -1 && t & (1 << traps[nv]);
            int w = myInv ^ nextInv ? graph[nv][v] : graph[v][nv];
            if(w == 0) continue;
            int nt = traps[nv] != -1 ? (t & (1 << traps[nv]) ? t & ~(1 << traps[nv]) : t | (1 << traps[nv])) : t;
            if(dist[nv][nt] > dist[v][t] + w) {
                dist[nv][nt] = dist[v][t] + w;
                pq.push({ nv, nt, dist[nv][nt] });
            }
        }
    }
    int res = INF;
    for (int j = 0; j < 1 << 10; j++)
        res = min(res, dist[E][j]);
    return res;
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> trapsI) {
    N = n;
    for (auto r : roads) {
        int w = graph[r[0]][r[1]];
        graph[r[0]][r[1]] = w == 0 ? r[2] : min(w, r[2]);
    }
    for(int i = 0; i < trapsI.size(); i++)
        traps[trapsI[i]] = i;
    return Dijkstra(start, end);
}
