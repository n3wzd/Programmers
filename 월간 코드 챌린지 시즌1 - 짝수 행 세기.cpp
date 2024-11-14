#include <vector>
using namespace std;
typedef long long ll;
const ll p = 1e7 + 19;
ll N, M, DP[301][301], A[301], C[301][301];
ll add(ll a, ll b) { return ((a % p) + (b % p)) % p; }
ll mul(ll a, ll b) { return ((a % p) * (b % p)) % p; }

void combination() {
    int L = max(N, M);
    for (int a = 0; a <= L; a++) {
        C[a][0] = C[a][a] = 1;
        for (int b = 1; b < a; b++)
            C[a][b] = add(C[a - 1][b - 1], C[a - 1][b]);
    }
}

void solve() {
    DP[0][0] = 1;
    for (int x = 1; x <= M; x++) {
        for (int k = 0; k <= N; k++) {
            for (int i = 0; i <= A[x]; i++) {
                ll nextK = k + (i * 2 - A[x]);
                if (nextK >= 0 && nextK <= N && A[x] - i >= 0)
                    DP[x][k] = add(DP[x][k], mul(DP[x - 1][nextK], mul(C[N - k][i], C[k][A[x] - i])));
            }
        }
    }
}

int solution(vector<vector<int>> a) {
    N = a.size(), M = a[0].size();
    for (int x = 1; x <= M; x++)
        for (int y = 0; y < N; y++)
            A[x] += a[y][x - 1];
    combination(); solve();
    return DP[M][0];
}
