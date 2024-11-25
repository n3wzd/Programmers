#include <vector>
using namespace std;
typedef long long ll;

ll solution(int a, int b, vector<int> G, vector<int> S, vector<int> W, vector<int> T) {
    ll lo = 0, hi = 4e14, N = G.size();
    while(lo < hi) {
        ll t = (lo + hi) / 2;
        ll sum = 0, sumG = 0, sumS = 0;
        for(int i = 0; i < N; i++) {
            ll mt = t / (T[i] * 2);
            mt += t - mt * (T[i] * 2) >= T[i] ? 1 : 0;
            sum += min(mt * W[i], (ll)G[i] + S[i]);
            sumG += min(mt * W[i], (ll)G[i]);
            sumS += min(mt * W[i], (ll)S[i]);
        }
        sum >= a + b && sumG >= a && sumS >= b ? hi = t : lo = t + 1;
    }
    return hi;
}
