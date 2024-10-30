#include <string>
#include <vector>
#include <queue>
using namespace std;
deque<int> row[50001], col[2];
int N, M, baseY;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    vector<vector<int>> answer;
    N = rc.size(), M = rc[0].size();
    for (int y = 0; y < N; y++)
        for (int x = 1; x < M - 1; x++)
            row[y].push_back(rc[y][x]);
    for (int x = 0; x < 2; x++)
        for (int y = 0; y < N; y++)
            col[x].push_back(rc[y][x * (M - 1)]);
    for (auto cmd : operations) {
        if (cmd == "Rotate") {
            if (M > 2) {
                int prevY = (baseY - 1 + N) % N;
                col[1].push_front(row[baseY].back()); row[baseY].pop_back();
                row[prevY].push_back(col[1].back()); col[1].pop_back();
                col[0].push_back(row[prevY].front()); row[prevY].pop_front();
                row[baseY].push_front(col[0].front()); col[0].pop_front();
            }
            else {
                col[1].push_front(col[0].front()); col[0].pop_front();
                col[0].push_back(col[1].back()); col[1].pop_back();
            }
        }
        if (cmd == "ShiftRow") {
            baseY = (baseY - 1 + N) % N;
            for (int x = 0; x < 2; x++)
                col[x].push_front(col[x].back()), col[x].pop_back();
        }
    }
    for (int y = 0; y < N; y++)
        for (int x = 1; x < M - 1; x++)
            rc[y][x] = row[(y + baseY) % N].front(), row[(y + baseY) % N].pop_front();
    for (int x = 0; x < 2; x++)
        for (int y = 0; y < N; y++)
            rc[y][x * (M - 1)] = col[x].front(), col[x].pop_front();
    return rc;
}
