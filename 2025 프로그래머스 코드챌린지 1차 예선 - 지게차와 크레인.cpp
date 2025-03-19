#include <string>
#include <vector>
#include <memory.h>
using namespace std;
vector<string> storage;
int N, M, answer, dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
bool visited[52][52];
void erase(int x, int y) { storage[y][x] = '.'; answer--; }

void DFS(int x, int y, char data) {
    if(x < 0 || x >= M || y < 0 || y >= N || visited[y][x])
        return;
    visited[y][x] = 1;
    if(storage[y][x] == data) 
        erase(x, y);
    else if(storage[y][x] == '.')
        for(int d = 0; d < 4; d++)
            DFS(x + dx[d], y + dy[d], data);
}

void grid(char data) {
    for(int y = 0; y < N; y++)
        for(int x = 0; x < M; x++)
            if(storage[y][x] == data)
                erase(x, y);
}

int solution(vector<string> S, vector<string> requests) {
    storage = S; N = S.size(); M = S[0].size(); answer = N * M;
    for(auto query : requests) {
        if(query.size() == 1) {
            for(int y = 0; y < N; y++)
                DFS(0, y, query[0]), DFS(M - 1, y, query[0]);
            for(int x = 0; x < M; x++)
                DFS(x, 0, query[0]), DFS(x, N - 1, query[0]);
            memset(visited, 0, sizeof(visited)); 
        } else
            grid(query[0]);
    }
    return answer;
}
