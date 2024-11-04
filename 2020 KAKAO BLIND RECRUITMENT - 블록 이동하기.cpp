#include <vector>
#include <queue>
struct Node { int x, y, a; };
using namespace std;
int N, M, dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
int dist[102][102][2]; // 0: hor, 1: ver
vector<vector<int>> board;
queue<Node> q;
bool isSafe(int x, int y) { return !(x < 0 || x >= M || y < 0 || y >= N || board[y][x]); }
void add(int x, int y, int a, int d) {
    if (isSafe(x, y) && isSafe(x + dx[a], y + dy[a]) && dist[y][x][a] == 0) {
        q.push({ x, y, a });
        dist[y][x][a] = d + 1;
    }
}

int solution(vector<vector<int>> boardI) {
    board = boardI; N = board.size(), M = board[0].size();
    q.push({ 0, 0, 0 }); dist[0][0][0] = 1;
    while (1) {
        auto c = q.front(); q.pop();
        int x = c.x, y = c.y, a = c.a;
        if ((x == M - 1 && y == N - 1) || (x + dx[a] == M - 1 && y + dy[a] == N - 1))
            return dist[y][x][a] - 1;

        for (int d = 0; d < 4; d++)
            add(x + dx[d], y + dy[d], a, dist[y][x][a]);
        if (a == 0) {
            if (isSafe(x + 1, y + 1))
                add(x, y, 1, dist[y][x][a]);
            if (isSafe(x, y + 1))
                add(x + 1, y, 1, dist[y][x][a]);
            if (isSafe(x + 1, y - 1))
                add(x, y - 1, 1, dist[y][x][a]);
            if (isSafe(x, y - 1))
                add(x + 1, y - 1, 1, dist[y][x][a]);
        }
        if (a == 1) {
            if (isSafe(x + 1, y + 1))
                add(x, y, 0, dist[y][x][a]);
            if (isSafe(x - 1, y + 1))
                add(x - 1, y, 0, dist[y][x][a]);
            if (isSafe(x + 1, y))
                add(x, y + 1, 0, dist[y][x][a]);
            if (isSafe(x - 1, y))
                add(x - 1, y + 1, 0, dist[y][x][a]);
        }
    }
    return 0;
}
