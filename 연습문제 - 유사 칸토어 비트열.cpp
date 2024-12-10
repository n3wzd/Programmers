using namespace std;
typedef long long ll;
int answer = 0;
ll M4[21] = { 1, }, M5[21] = { 1, };

void R(ll lo, ll n, ll l, ll r) {
    ll hi = lo + M5[n] - 1, t = M5[n] / 5;
    if(lo > r || hi < l)
        return;
    if(lo >= l && hi <= r) {
        answer += M4[n];
        return;
    }
    for(int i = 0; i < 5; i++)
        if(i != 2)
            R(lo + t * i, n - 1, l, r);
}

int solution(int n, ll l, ll r) {
    for(int i = 1; i <= n; i++)
        M4[i] = M4[i - 1] * 4, M5[i] = M5[i - 1] * 5;
    R(0, n, l - 1, r - 1);
    return answer;
}
