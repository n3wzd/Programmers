#include <vector>
#include <queue>
using namespace std;
struct Edge { int v, w; };
struct cmp { bool operator()(Edge& a, Edge& b) { return a.w > b.w; }};
const int INF = 99999999;
int N, answer, dist[51];
bool visited[51];
vector<Edge> graph[51];
priority_queue<Edge, vector<Edge>, cmp> pq;

void Dijkstra() {
	for (int i = 1; i <= N; i++)
		dist[i] = INF;
	dist[1] = 0;
	pq.push({ 1, 0 });
	while (!pq.empty()) {
		int v = pq.top().v; pq.pop();
		if (visited[v]) continue;
		visited[v] = 1;
		for (auto n : graph[v]) {
			if (dist[v] + n.w < dist[n.v]) {
				dist[n.v] = dist[v] + n.w;
				pq.push({ n.v, dist[n.v] });
			}
		}
	}
}

int solution(int n, vector<vector<int>> roads, int K) {
    N = n;
    for(auto road : roads) {
        graph[road[0]].push_back({road[1], road[2]});
        graph[road[1]].push_back({road[0], road[2]});
    }
    Dijkstra();
    for(int i = 1; i <= N; i++)
        if(dist[i] <= K)
            answer++;
    return answer;
}
