#include <vector>
using namespace std;
int N, dx[9] = { 1, 0, -1, 0, 1, 1, -1, -1, 0 }, dy[9] = { 0, 1, 0, -1, 1, -1, 1, -1, 0 };
bool board[104][104][2];

bool isSafe(int x, int y, int a) {
    return (a == 0) ?
        (y == 1 || (y > 1 && board[y - 1][x][0]) || board[y][x - 1][1] || board[y][x][1]) :
        ((board[y - 1][x][0] || board[y - 1][x + 1][0]) || (board[y][x - 1][1]) && (board[y][x + 1][1]));
}

void install(int x, int y, int a) {
    if (isSafe(x, y, a))
        board[y][x][a] = 1;
}

void uninstall(int x, int y, int a) {
    board[y][x][a] = 0;
    bool ok = 1;
    for (int d = 0; d < 9; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        for (int b = 0; b < 2; b++) {
            if (board[ny][nx][b])
                ok &= isSafe(nx, ny, b);
        }
    }
    if (!ok) board[y][x][a] = 1;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    N = n + 1; vector<vector<int>> answer;
    for (auto frame : build_frame) {
        frame[3] == 1 ?
            install(frame[0] + 1, frame[1] + 1, frame[2]) :
            uninstall(frame[0] + 1, frame[1] + 1, frame[2]);
    }
    for (int x = 1; x <= N; x++)
        for (int y = 1; y <= N; y++)
            for (int a = 0; a < 2; a++)
                if (board[y][x][a])
                    answer.push_back({ x - 1, y - 1, a });
    return answer;
}
