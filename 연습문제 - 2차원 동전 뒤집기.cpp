#include <vector>
using namespace std;
int N, M, answer = -1;
bool selected[21];
vector<vector<int>> S, T;

void BT(int level, int cnt) {
    if(level == N + M) {
        bool ok = 1;
        for(int y = 0; y < N; y++)
            for(int x = 0; x < M; x++)
                ok &= T[y][x] == (selected[x] ^ selected[y + M] ? (S[y][x] == 1 ? 0 : 1) : S[y][x]);
        if(ok)
            answer = answer != -1 ? min(answer, cnt) : cnt;
        return;
    }
    selected[level] = 1;
    BT(level + 1, cnt + 1);
    selected[level] = 0;
    BT(level + 1, cnt);
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    S = beginning, T = target; N = S.size(), M = S[0].size();
    BT(0, 0);
    return answer;
}
