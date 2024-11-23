#include <iostream>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) { return (a % b == 0) ? b : gcd(b, a % b); }

ll solution(int w, int h) {
    ll area = (ll)w * h, g = gcd(w, h);
    w /= g, h /= g;
    ll n = min(w, h), m = max(w, h);
    return area - (n + m - 1) * g;
}
