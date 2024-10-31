#include <vector>
#include <cmath>
using namespace std;
vector<vector<int>> board;
int N, M, resTurn, dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
bool isOut(int x, int y) { return x < 0 || x >= M || y < 0 || y >= N || board[y][x] == 0; }
bool isWin(int player, int target) { return player * target > 0; }

bool willLose(int x, int y) {
    bool flag = 1;
    for (int d = 0; d < 4; d++)
        flag &= isOut(x + dx[d], y + dy[d]);
    return flag || board[y][x] == 0;
}

int game(int x1, int y1, int x2, int y2, int player, int turn) {
    if (willLose(x1, y1))
        return -turn * player;
    vector<int> winCase, loseCase;
    board[y1][x1] = 0;
    for (int d = 0; d < 4; d++) {
        int nx = x1 + dx[d], ny = y1 + dy[d];
        if (!isOut(nx, ny)) {
            int res = game(x2, y2, nx, ny, player * -1, turn + 1);
            isWin(player, res) ? winCase.push_back(res) : loseCase.push_back(res);
        }
    }
    board[y1][x1] = 1;

    if (winCase.size() > 0) {
        int res = 99;
        for (int r : winCase)
            res = min(res, abs(r));
        return res * player;
    }
    else {
        int res = 0;
        for (int r : loseCase)
            res = max(res, abs(r));
        return -res * player;
    }
}

int solution(vector<vector<int>> b, vector<int> aloc, vector<int> bloc) {
    N = b.size(), M = b[0].size(), board = b;
    return abs(game(aloc[1], aloc[0], bloc[1], bloc[0], 1, 0));
}
