#include <vector>
#include <queue>
using namespace std;
struct Node { int x, y, axis, cost; };
struct cmp { bool operator()(const Node& a, const Node& b) { return a.cost > b.cost; } };
int N, cost[26][26][2], dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
bool visited[26][26][2];
const int INF = 1 << 29;

int solution(vector<vector<int>> board) {
    priority_queue<Node, vector<Node>, cmp> pq;
    N = board.size();
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            cost[y][x][0] = cost[y][x][1] = INF;
    cost[0][0][0] = cost[0][0][1] = 0;
    pq.push({ 0, 0, 0 }); pq.push({ 0, 0, 1 });
    while (!pq.empty()) {
        int x = pq.top().x, y = pq.top().y, a = pq.top().axis; pq.pop();
        if (visited[y][x][a])
            continue;
        visited[y][x][a] = 1;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d], na = d % 2;
            if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[ny][nx][na] || board[ny][nx] == 1)
                continue;
            int ncost = cost[y][x][a] + (a == na ? 100 : 600);
            if (ncost < cost[ny][nx][na]) {
                cost[ny][nx][na] = ncost;
                pq.push({ nx, ny, na, ncost });
            }
        }
    }
    return min(cost[N - 1][N - 1][0], cost[N - 1][N - 1][1]);
}
