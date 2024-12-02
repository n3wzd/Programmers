#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> maps;
bool visited[101][101];
int N, M, dx[] = { 1, 0 , -1, 0 }, dy[] = { 0, 1, 0, -1 };

int DFS(int x, int y) {
    visited[y][x] = 1;
    int sum = maps[y][x] - '0';
    for(int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if(nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[ny][nx] && maps[ny][nx] != 'X')
            sum += DFS(nx, ny);
    }
    return sum;
}

vector<int> solution(vector<string> mapI) {
    maps = mapI; N = maps.size(), M = maps[0].size();
    vector<int> answer;
    for(int y = 0; y < N; y++)
        for(int x = 0; x < M; x++)
            if(!visited[y][x] && maps[y][x] != 'X')
                answer.push_back(DFS(x, y));
    sort(answer.begin(), answer.end());
    if(answer.empty())
        answer.push_back(-1);
    return answer;
}
