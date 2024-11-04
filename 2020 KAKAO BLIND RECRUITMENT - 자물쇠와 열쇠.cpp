#include <string>
#include <vector>
#include <iostream>
using namespace std;
int N, M;
bool key[4][21][21];
vector<vector<int>> lock;
bool isOut(int x, int y) { return x < 0 || x >= M || y < 0 || y >= M; }

void rotate(int x, int y, int d) {
    bool even = M % 2 == 0; int c = even ? M / 2 - 1 : M / 2;
    int dx = x - c + (even && x <= c ? -1 : 0), dy = y - c + (even && y <= c ? -1 : 0);
    int nx = c + dy, ny = c - dx;
    key[d + 1][ny + (even && ny <= c ? 1 : 0)][nx + (even && nx <= c ? 1 : 0)] = key[d][y][x];
}

void rotateAll() {
    for (int d = 0; d < 3; d++)
        for (int y = 0; y < M; y++)
            for (int x = 0; x < M; x++)
                rotate(x, y, d);
}

bool isPass(int d, int by, int bx) {
    bool ok = 1;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            ok &= isOut(bx + x, by + y) ? lock[y][x] : (lock[y][x] ^ key[d][by + y][bx + x]);
    return ok;
}

bool solution(vector<vector<int>> keyI, vector<vector<int>> lockI) {
    M = keyI.size(), N = lockI.size(); lock = lockI;
    bool ok = 1;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            ok &= lock[y][x];
    if (ok) return 1;
    for (int y = 0; y < M; y++)
        for (int x = 0; x < M; x++)
            key[0][y][x] = keyI[y][x];
    rotateAll();
    for (int y = -(N - 1); y < M; y++)
        for (int x = -(N - 1); x < M; x++)
            for (int d = 0; d < 4; d++)
                if (isPass(d, x, y))
                    return 1;
    return 0;
}
