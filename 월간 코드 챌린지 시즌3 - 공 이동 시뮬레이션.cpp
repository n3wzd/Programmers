#include <vector>
using namespace std;
typedef long long ll;
ll dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 };

ll solution(int N, int M, int Y, int X, vector<vector<int>> Q) {
    ll h1 = 0, h2 = M - 1, v1 = 0, v2 = N - 1, x = 0, y = 0, answer = 0;
    for(auto q : Q) {
        x += dx[q[0]] * q[1]; y += dy[q[0]] * q[1];
        ll dh = h1 + (M - 1 - h2), dv = v1 + (N - 1 - v2);
        if(x < 0)
            h1 = min(h1 - x, h2), x = 0;
        if(x > dh)
            h2 = max(h2 - (x - dh), h1), x = h1 + (M - 1 - h2);
        if(y < 0)
            v1 = min(v1 - y, v2), y = 0;
        if(y > dv)
            v2 = max(v2 - (y - dv), v1), y = v1 + (N - 1 - v2);
    }
    ll x1 = x, x2 = x + h2 - h1, y1 = y, y2 = y + v2 - v1;
    ll sl = h1 + 1, sr = M - 1 - h2 + 1, su = v1 + 1, sd = N - 1 - v2 + 1;
    if(h1 == h2) sl--;
    if(v1 == v2) su--;
    if(X == x1 && Y == y1) answer += sl * su;
    if(X == x1 && Y == y2) answer += sl * sd;
    if(X == x2 && Y == y1) answer += sr * su;
    if(X == x2 && Y == y2) answer += sr * sd;
    if(X == x1 && Y > y1 && Y < y2) answer += sl;
    if(X == x2 && Y > y1 && Y < y2) answer += sr;
    if(Y == y1 && X > x1 && X < x2) answer += su;
    if(Y == y2 && X > x1 && X < x2) answer += sd;
    if(X > x1 && X < x2 && Y > y1 && Y < y2) answer += 1;
    return answer;
}
