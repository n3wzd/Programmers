#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;
vector<vector<string>> R; vector<int> candidate;
bool selected[9];
int N, M, cnt;

void combination(int len, int start) {
    if (len == 0) {
        int key = 0;
        for (int x = 0; x < M; x++)
            if (selected[x])
                key |= 1 << x;
        for (auto ck : candidate) {
            bool ok = 1;
            for (int x = 0; x < M; x++)
                if (ck & 1 << x)
                    ok &= !((key & 1 << x) ^ (ck & 1 << x));
            if (ok) return;
        }
        set<string> S;
        for (int y = 0; y < N; y++) {
            string tmp = "";
            for (int x = 0; x < M; x++)
                if (selected[x])
                    tmp += R[y][x] + "|";
            if (S.find(tmp) != S.end())
                return;
            S.insert(tmp);
        }
        candidate.push_back(key);
        cnt++; return;
    }
    for (int i = start; i < M; i++) {
        selected[i] = 1;
        combination(len - 1, i + 1);
        selected[i] = 0;
    }
}

int solution(vector<vector<string>> relation) {
    R = relation; N = R.size(), M = R[0].size();
    for (int d = 1; d <= M; d++)
        combination(d, 0);
    return cnt;
}
