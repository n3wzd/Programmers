#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
bool visited[501][501][4];
vector<string> G; vector<int> answer;

void cycle(int x, int y, int d, int sx, int sy, int sd, int len = 0) {
    if(x == sx && y == sy && d == sd && len > 0) {
        answer.push_back(len);
        return;
    }
    visited[y][x][d] = 1;
    if(G[y][x] == 'L')
        d = (d + 3) % 4;
    if(G[y][x] == 'R')
        d = (d + 1) % 4;
    cycle((x + dx[d] + M) % M, (y + dy[d] + N) % N, d, sx, sy, sd, len + 1);
}

vector<int> solution(vector<string> grid) {
    N = grid.size(), M = grid[0].size(); G = grid;
    for(int y = 0; y < N; y++)
        for(int x = 0; x < M; x++)
            for(int d = 0; d < 4; d++)
                if(!visited[y][x][d])
                    cycle(x, y, d, x, y, d);
    sort(answer.begin(), answer.end());
    return answer;
}
