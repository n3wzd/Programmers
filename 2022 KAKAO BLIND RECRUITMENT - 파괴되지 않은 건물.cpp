#include <vector>
using namespace std;
int N, M, cnt, dtx, dty[1002], dtRect[1002][1002];

int solution(vector<vector<int>> board, vector<vector<int>> skills) {
    N = board.size(), M = board[0].size();
    for (auto s : skills) {
        dtRect[s[1]][s[2]] += s[5] * (s[0] == 1 ? -1 : 1);
        dtRect[s[1]][s[4] + 1] += s[5] * (s[0] == 1 ? 1 : -1);
        dtRect[s[3] + 1][s[2]] += s[5] * (s[0] == 1 ? 1 : -1);
        dtRect[s[3] + 1][s[4] + 1] += s[5] * (s[0] == 1 ? -1 : 1);
    }

    for (int y = 0; y < N; y++) {
        dtx = 0;
        for (int x = 0; x < M; x++)
            dty[x] += dtRect[y][x];
        for (int x = 0; x < M; x++) {
            dtx += dty[x];
            cnt += board[y][x] + dtx > 0 ? 1 : 0;
        }
    }
    return cnt;
}
