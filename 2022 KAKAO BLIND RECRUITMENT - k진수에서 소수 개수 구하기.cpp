#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
queue<int> q;
int cnt = 0;

bool isPrime(ll n) {
    ll sq = sqrt(n);
    for (int d = 2; d <= sq; d++)
        if (n % d == 0)
            return 0;
    return 1;
}

void scan() {
    if (q.empty())
        return;
    ll p = 0, d = 1;
    while (!q.empty()) {
        p += q.front() * d; q.pop();
        d *= 10;
    }
    cnt += (p != 1 && isPrime(p)) ? 1 : 0;
}

int solution(int n, int k) {
    while (n > 0) {
        n% k != 0 ? q.push(n % k) : scan();
        n /= k;
    }
    scan();
    return cnt;
}
