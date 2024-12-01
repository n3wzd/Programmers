#include <vector>
using namespace std;
typedef long long ll;

ll C(ll r, bool outline) {
    ll a = 0, da = 0;
    for(ll x = 1, y = r; x <= r; x++) {
        while((outline ? r * r < x * x + y * y : r * r <= x * x + y * y) && y > 0)
            da++, y--;
        a += da;
    }
    return (2 * r + 1) * (2 * r + 1) - (a * 4 + (outline ? 0 : 4));
}

ll solution(int r1, int r2) {
    return C(r2 , 1) - C(r1, 0);
}
