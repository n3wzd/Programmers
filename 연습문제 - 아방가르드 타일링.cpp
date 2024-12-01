typedef long long ll;
const ll p = 1e9 + 7;
ll DP[100001] = { 1, 1, }, PS[100001], A[] = { 0, 1, 2, 5 };
ll add(ll a, ll b) { return (a + b) % p; }
ll mul(ll a, ll b) { return (a * b) % p; }

int solution(int n) {
    for(int i = 2; i <= n; i++) {
        for(int d = 1; d <= 3 && i >= d; d++)
            DP[i] = add(DP[i], mul(DP[i - d], A[d]));
        for(int d = 4; d <= 6 && i >= d; d++)
            PS[i] = add(PS[i], mul(DP[i - d], (d % 3 == 0 ? 4 : 2)));
        if (i >= 3)
            PS[i] = add(PS[i], PS[i - 3]);
        DP[i] = add(DP[i], PS[i]);
    }
    return DP[n];
}
