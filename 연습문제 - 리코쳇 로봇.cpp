#include <string>
#include <vector>
#include <queue>
using namespace std;
struct Point { int x, y; };
int dist[101][101], dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };

int solution(vector<string> board) {
    int N = board.size(), M = board[0].size();
    queue<Point> q; Point G;
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < M; x++) {
            if(board[y][x] == 'R')
                q.push({ x, y }), dist[y][x] = 1;
            if(board[y][x] == 'G')
                G = { x, y };
        }
    }
    while(!q.empty()) {
        Point c = q.front(); q.pop();
        int x = c.x, y = c.y;
        if(x == G.x && y == G.y)
            return dist[y][x] - 1;
        for(int d = 0; d < 4; d++) {
            int nx = x, ny = y;
            while(nx >= 0 && nx < M && ny >= 0 && ny < N && board[ny][nx] != 'D')
                nx += dx[d], ny += dy[d];
            nx -= dx[d], ny -= dy[d];
            if(dist[ny][nx] > 0)
                continue;
            q.push({ nx, ny });
            dist[ny][nx] = dist[y][x] + 1;
        }
    }
    return -1;
}
