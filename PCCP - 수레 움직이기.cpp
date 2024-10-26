#include <vector>
using namespace std;
struct Point { int x, y; };
struct PointSet { Point r = { 0, 0 }, b = { 0, 0 }; };
int N, M, minTurn = 999, dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
vector<vector<int>> board;
bool visitedR[4][4], visitedB[4][4];
Point RG, BG;

void DFS(Point r, Point b, int turn) {
    bool isRGoal = r.x == RG.x && r.y == RG.y, isBGoal = b.x == BG.x && b.y == BG.y;
    if (isRGoal && isBGoal) {
        minTurn = min(turn, minTurn);
        return;
    }
    visitedR[r.y][r.x] = visitedB[b.y][b.x] = 1;
    int nx, ny, mx, my;
    for (int d1 = 0; d1 < 4; d1++) {
        if (isRGoal)
            nx = r.x, ny = r.y, d1 += 4;
        else
            nx = r.x + dx[d1], ny = r.y + dy[d1];
        if (nx < 0 || nx >= M || ny < 0 || ny >= N || board[ny][nx] == 5 || (visitedR[ny][nx] && !isRGoal))
            continue;
        for (int d2 = 0; d2 < 4; d2++) {
            if (isBGoal)
                mx = b.x, my = b.y, d2 += 4;
            else
                mx = b.x + dx[d2], my = b.y + dy[d2];
            if (mx < 0 || mx >= M || my < 0 || my >= N || board[my][mx] == 5 || (visitedB[my][mx] && !isBGoal))
                continue;
            if ((nx == mx && ny == my) || (nx == b.x && ny == b.y && mx == r.x && my == r.y))
                continue;
            DFS({ nx, ny }, { mx, my }, turn + 1);
        }
    }
    visitedR[r.y][r.x] = visitedB[b.y][b.x] = 0;
}

int solution(vector<vector<int>> maze) {
    Point r, b;
    board = maze, N = maze.size(), M = maze[0].size();
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (maze[y][x] == 1) r = { x, y };
            if (maze[y][x] == 2) b = { x, y };
            if (maze[y][x] == 3) RG = { x, y };
            if (maze[y][x] == 4) BG = { x, y };
        }
    }
    DFS(r, b, 0);
    return minTurn == 999 ? 0 : minTurn;
}
