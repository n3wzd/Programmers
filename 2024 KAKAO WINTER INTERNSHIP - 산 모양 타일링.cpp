#include <vector>
using namespace std;
vector<int> tops;
int N, DP[200003];
const int p = 10007;
int ModAdd(int a, int b) { return ((a % p) + (b % p)) % p; }
int ModMul(int a, int b) { return ((a % p) * (b % p)) % p; }

int solution(int n, vector<int> tops1) {
    tops = tops1; N = 2 * n + 1; DP[0] = DP[1] = 1;
    for (int i = 2; i <= N; i++)
        DP[i] = (i % 2 == 0)
        ? ModAdd(ModMul(DP[i - 1], (tops[i / 2 - 1] ? 2 : 1)), DP[i - 2])
        : ModAdd(DP[i - 1], DP[i - 2]);
    return DP[N];
}
