using namespace std;
typedef long long ll;

ll solution(int k2, int d2) {
    ll k = k2, d = d2, answer = 0, y = (d / k) * k;
    for(ll x = 0; x <= d; x += k) {
        while(d * d < x * x + y * y)
            y -= k;
        answer += y / k + 1;
    }
    return answer;
}
