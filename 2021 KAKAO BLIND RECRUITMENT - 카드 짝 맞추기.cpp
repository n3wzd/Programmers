#include <vector>
#include <queue>
#include <cstring>
using namespace std;
struct Point { int x, y; };
int minDist = 999999, dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
bool visited[4][4];
vector<vector<int>> board;
bool isOut(int x, int y) { return x < 0 || x >= 4 || y < 0 || y >= 4; }
Point findOther(int tx, int ty) {
    for (int y = 0; y < 4; y++)
        for (int x = 0; x < 4; x++)
            if (board[y][x] == board[ty][tx] && !(x == tx && y == ty))
                return { x, y };
}

int BFS(int x, int y, int gx, int gy) {
    memset(visited, 0, sizeof(visited));
    queue<Point> q; q.push({ x, y });
    visited[y][x] = 1;
    int dist = 0;
    while (1) {
        int size = q.size();
        while (size--) {
            Point c = q.front(); q.pop();
            if (c.x == gx && c.y == gy)
                return dist;
            for (int d = 0; d < 4; d++) {
                int nx = c.x + dx[d], ny = c.y + dy[d];
                if (!isOut(nx, ny) && !visited[ny][nx]) {
                    visited[ny][nx] = 1;
                    q.push({ nx, ny });
                }
            }
            for (int d = 0; d < 4; d++) {
                int nx = c.x, ny = c.y;
                for (; !isOut(nx + dx[d], ny + dy[d]); nx += dx[d], ny += dy[d])
                    if (board[ny][nx] > 0 && !(nx == c.x && ny == c.y))
                        break;
                if (!visited[ny][nx]) {
                    visited[ny][nx] = 1;
                    q.push({ nx, ny });
                }
            }
        }
        dist++;
    }
}

void BT(int x, int y, int distSum) {
    bool isEmpty = 1;
    for (int cy1 = 0; cy1 < 4; cy1++) {
        for (int cx1 = 0; cx1 < 4; cx1++) {
            if (board[cy1][cx1] > 0) {
                int card = board[cy1][cx1];
                Point p = findOther(cx1, cy1); int cx2 = p.x, cy2 = p.y;
                int dist1 = BFS(x, y, cx1, cy1), dist2 = BFS(cx1, cy1, cx2, cy2);
                board[cy2][cx2] = board[cy1][cx1] = 0;
                BT(cx2, cy2, distSum + dist1 + dist2 + 2);
                board[cy2][cx2] = board[cy1][cx1] = card;
                isEmpty = 0;
            }
        }
    }
    if (isEmpty)
        minDist = min(minDist, distSum);
}

int solution(vector<vector<int>> boardI, int r, int c) {
    board = boardI; BT(c, r, 0);
    return minDist;
}
