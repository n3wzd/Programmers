#include <vector>
using namespace std;
int N, M, cnt = 1, gx, gy, rx1, rx2, ry1, ry2, dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
vector<vector<int>> board;
int visited[51][51];

void DFS(int x, int y, int id) {
    rx1 = min(rx1, x); rx2 = max(rx2, x);
    ry1 = min(ry1, y); ry2 = max(ry2, y);
    visited[y][x] = cnt;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && visited[ny][nx] != cnt && board[ny][nx] == id)
            DFS(nx, ny, id);
    }
}

bool canFill(int x, int y) {
    while (y >= 0 && board[y][x] == 0) y--;
    return y < 0 ? 1 : 0;
}

void isRect(int x, int y) {
    rx1 = rx2 = x, ry1 = ry2 = y;
    DFS(x, y, board[y][x]);
    bool ok = 1;
    for (int ty = ry1; ty <= ry2; ty++)
        for (int tx = rx1; tx <= rx2; tx++)
            if (board[ty][tx] != board[y][x])
                ok &= canFill(tx, ty);
    if (ok) {
        for (int ty = ry1; ty <= ry2; ty++)
            for (int tx = rx1; tx <= rx2; tx++)
                board[ty][tx] = 0;
        cnt++; gx = 0;
    }
}

int solution(vector<vector<int>> B) {
    board = B, N = board.size();
    for (gy = 0; gy < N; gy++)
        for (gx = 0; gx < N; gx++)
            if (visited[gy][gx] != cnt && board[gy][gx] > 0)
                isRect(gx, gy);
    return cnt - 1;
}
