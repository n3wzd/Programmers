#include <vector>
using namespace std;
const int MAXN = 99999;
int N, cache[32][1 << 8][32];
vector<int> weak, dist;

int DP(int n, int team, int L) {
    if (n >= L)
        return 0;
    if (cache[n][team][L] > 0)
        return cache[n][team][L];
    cache[n][team][L] = MAXN;
    for (int i = 0; i < dist.size(); i++) {
        if (!(team & (1 << i))) {
            int next = n;
            while (next < L && weak[next] <= weak[n] + dist[i]) next++;
            cache[n][team][L] = min(cache[n][team][L], DP(next, team | (1 << i), L) + 1);
        }
    }
    return cache[n][team][L];
}

int solution(int n, vector<int> weakI, vector<int> distI) {
    N = weakI.size(); weak = weakI, dist = distI;
    for (int i = 0; i < N; i++)
        weak.push_back(n + weak[i]);
    int res = DP(0, 0, N);
    for (int i = 1; i < N; i++)
        res = min(res, DP(i, 0, N + i));
    return res == MAXN ? -1 : res;
}
