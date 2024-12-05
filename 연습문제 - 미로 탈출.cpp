#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
struct Point { int x, y; };
vector<string> maps;
int N, M, dist[101][101], dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };

int BFS(Point S, Point E) {
    memset(dist, 0, sizeof(dist));
    queue<Point> q; q.push(S);
    dist[S.y][S.x] = 1;
    while(!q.empty()) {
        Point c = q.front(); q.pop();
        int x = c.x, y = c.y;
        if(x == E.x && y == E.y)
            return dist[y][x] - 1;
        for(int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if(nx < 0 || nx >= M || ny < 0 || ny >= N || dist[ny][nx] > 0 || maps[ny][nx] == 'X')
                continue;
            q.push({ nx, ny });
            dist[ny][nx] = dist[y][x] + 1;
        }
    }
    return -1e9;
}

int solution(vector<string> MI) {
    maps = MI; Point S, L, E; N = maps.size(), M = maps[0].size();
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < M; x++) {
            if(maps[y][x] == 'S')
                S = { x, y };
            if(maps[y][x] == 'E')
                E = { x, y };
            if(maps[y][x] == 'L')
                L = { x, y };
        }
    }
    int answer = BFS(S, L) + BFS(L, E);
    return answer < 0 ? -1 : answer;
}
