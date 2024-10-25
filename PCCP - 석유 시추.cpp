#include <string>
#include <vector>
#include <queue>
using namespace std;
int N, M, genBank = 1, dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, -1, 0, 1 };
vector<vector<int>> landBoard; vector<int> oilBank = { 0 }; vector<bool> oilVisited;
int oilBoard[501][501];

int DFS(int x, int y, int id) {
    int sum = 1;
    oilBoard[y][x] = id;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx >= 0 && nx < M && ny >= 0 && ny < N && oilBoard[ny][nx] == 0 && landBoard[ny][nx] == 1)
            sum += DFS(nx, ny, id);
    }
    return sum;
}

int solution(vector<vector<int>> land) {
    landBoard = land; N = land.size(), M = land[0].size();
    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            if (landBoard[y][x] == 1 && oilBoard[y][x] == 0)
                oilBank.push_back(DFS(x, y, genBank++));
    for (int oil : oilBank)
        oilVisited.push_back(0);

    int maxOil = 0;
    for (int x = 0; x < M; x++) {
        int oil = 0;
        queue<int> q;
        for (int y = 0; y < N; y++) {
            int id = oilBoard[y][x];
            if (id > 0 && !oilVisited[id]) {
                oilVisited[id] = 1;
                q.push(id);
            }
        }
        while (!q.empty()) {
            int id = q.front(); q.pop();
            oil += oilBank[id];
            oilVisited[id] = 0;
        }
        maxOil = max(maxOil, oil);
    }
    return maxOil;
}
