#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
struct Node { ll x, y, w; };
const ll p = 1e9 + 7;
vector<vector<int>> grid;
vector<int> drag;
ll graph[64][64], graph2[64][64];
int N, M, dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
ll add(ll a, ll b) { return (a + b) % p; }
ll mul(ll a, ll b) { return (a * b) % p; }

void BFS(int sx, int sy) {
    queue<Node> q; q.push({ sx, sy, 1 });
    for(int d = 0; d < drag.size(); d++) {
        ll tmp[8][8] = { 0, };
        int size = q.size();
        while(size--) {
            Node node = q.front(); q.pop();
            ll x = node.x, y = node.y, w = node.w;
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && nx < M && ny >= 0 && ny < N && grid[ny][nx] - grid[y][x] == drag[d])
                    tmp[ny][nx] = add(tmp[ny][nx], w);
            }
        }
        for(int y = 0; y < N; y++)
            for(int x = 0; x < M; x++)
                if(tmp[y][x] > 0)
                    q.push({ x, y, tmp[y][x] });
    }
    while(!q.empty()) {
        Node node = q.front(); q.pop();
        graph[sy * M + sx][node.y * M + node.x] = node.w;
    }
}

void matMul(ll target[64][64]) {
	ll tmp[64][64] = { 0, };
	for (int a = 0; a < N * M; a++)
		for (int b = 0; b < N * M; b++)
			for (int c = 0; c < N * M; c++)
				tmp[a][b] = add(tmp[a][b], mul(graph[a][c], target[c][b]));
	for (int a = 0; a < N * M; a++)
		for (int b = 0; b < N * M; b++)
			target[a][b] = tmp[a][b];
}

ll sumAll() {
    ll sum = 0;
    for (int a = 0; a < N * M; a++)
		for (int b = 0; b < N * M; b++)
			sum = add(sum, graph2[a][b]);
    return sum;
}

int solution(vector<vector<int>> gridI, vector<int> dI, int k) {
    grid = gridI, drag = dI;
    N = grid.size(), M = grid[0].size();
    for(int y = 0; y < N; y++)
        for(int x = 0; x < M; x++)
            BFS(x, y);
    for (int a = 0; a < N * M; a++)
        graph2[a][a] = 1;
    while (k > 1) {
		if (k % 2 != 0)
            matMul(graph2);
		matMul(graph);
		k /= 2;
	}
	matMul(graph2);
    return sumAll();
}
