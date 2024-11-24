#include <vector>
#include <string>
using namespace std;
typedef long long ll;

vector<string> solution(vector<vector<int>> lines) {
    vector<string> answer;
    vector<vector<ll>> cross;
    ll N = lines.size(), x1 = 1e12, x2 = -1e12, y1 = 1e12, y2 = -1e12;
    for(ll i = 0; i < N; i++) {
        for(ll j = i + 1; j < N; j++) {
            auto L1 = lines[i], L2 = lines[j];
            ll det = (ll)L1[0] * L2[1] - (ll)L2[0] * L1[1];
            ll A = (-(ll)L2[1] * L1[2] + (ll)L1[1] * L2[2]);
            ll B = ((ll)L2[0] * L1[2] - (ll)L1[0] * L2[2]);
            if(det != 0 && A % det == 0 && B % det == 0) {
                ll x = A / det, y = B / det;
                x1 = min(x1, x), x2 = max(x2, x);
                y1 = min(y1, y), y2 = max(y2, y);
                cross.push_back({ x, y });
            }
        }
    }
    for(ll y = y1; y <= y2; y++)
        answer.push_back(string(x2 - x1 + 1, '.'));
    for(auto c : cross)
        answer[y2 - c[1]][c[0] - x1] = '*';
    return answer;
}
