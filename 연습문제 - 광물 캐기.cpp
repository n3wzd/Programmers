#include <string>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
vector<string> M;
int cache[6][6][6], N, STA[3][3] = { { 1, 1, 1 }, { 5, 1, 1 }, { 25, 5, 1 } };
map<string, int> dict;

int MANA(int m, int p) {
    int c = 0;
    for(int i = 0; i < 5 && m + i < M.size(); i++)
        c += STA[p][dict[M[m + i]]];
    return c;
}

int DP(int d, int i, int s) {
    int m = (N - (d + i + s)) * 5;
    if(cache[d][i][s] > 0)
        return cache[d][i][s];
    if(d < 0 || i < 0 || s < 0)
        return INF;
    if((d == 0 && i == 0 && s == 0) || m >= M.size())
        return 0;
    cache[d][i][s] = DP(d - 1, i, s) + MANA(m, 0);
    cache[d][i][s] = min(cache[d][i][s], DP(d, i - 1, s) + MANA(m, 1));
    cache[d][i][s] = min(cache[d][i][s], DP(d, i, s - 1) + MANA(m, 2));
    return cache[d][i][s];
}

int solution(vector<int> P, vector<string> minerals) {
    M = minerals; N = P[0] + P[1] + P[2];
    dict["diamond"] = 0, dict["iron"] = 1, dict["stone"] = 2;
    return DP(P[0], P[1], P[2]);
}
