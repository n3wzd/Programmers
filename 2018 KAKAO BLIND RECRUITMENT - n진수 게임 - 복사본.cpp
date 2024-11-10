#include <string>
#include <vector>
#include <cstring>
using namespace std;
bool visited[5][5];
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
vector<string> board;
bool pass(int x, int y) { return x >= 0 && x < 5 && y >= 0 && y < 5 && !visited[y][x] && board[y][x] != 'X'; }

bool DFS(int x, int y, int depth = 0, bool init = 1) {
    if (depth == 3)
        return 1;
    if (init)
        memset(visited, 0, sizeof(visited));
    else if (board[y][x] == 'P')
        return 0;
    bool flag = 1;
    visited[y][x] = 1;
    for (int d = 0; d < 4; d++)
        if (pass(x + dx[d], y + dy[d]))
            flag &= DFS(x + dx[d], y + dy[d], depth + 1, 0);
    return flag;
}

int solve(vector<string> place) {
    board = place;
    bool flag = 1;
    for (int y = 0; y < 5; y++)
        for (int x = 0; x < 5; x++)
            if (board[y][x] == 'P')
                flag &= DFS(x, y);
    return flag ? 1 : 0;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (auto place : places)
        answer.push_back(solve(place));
    return answer;
}
