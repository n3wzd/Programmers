#include <vector>
#include <unordered_map>
using namespace std;
typedef long long ll;
unordered_map<ll, ll> parent;
bool isExist(ll n) { return parent[n] != 0; }

ll Find(ll n) {
    ll p = n, p2 = n;
    while (parent[p] != -1) p = parent[p];
    while (parent[p2] != -1) {
        ll tmp = parent[p2];
        parent[p2] = p;
        p2 = tmp;
    }
    return p;
}

void Union(ll a, ll b) {
    ll p1 = Find(a);
    ll p2 = Find(b);
    p1 > p2 ? parent[p2] = p1 : parent[p1] = p2;
}

vector<ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer;
    for (auto num : room_number) {
        ll next = isExist(num) ? Find(num) + 1 : num;
        parent[next] = -1;
        answer.push_back(next);
        if (isExist(next + 1))
            Union(next, next + 1);
        if (isExist(next - 1))
            Union(next, next - 1);
    }
    return answer;
}
