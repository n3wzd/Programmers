#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll stringToInt(string s) {
    ll v = 0, m = 1;
    for(int i = s.size() - 1; i >= 0; i--) {
        v += (s[i] - 'a' + 1) * m;
        m *= 26;
    }
    return v;
}
string intToString(ll n) {
    string s = "";
    while(n > 0) {
        s += string(1, 'a' + ((n - 1) % 26));
        n = (n - 1) / 26;
    }
    reverse(s.begin(), s.end());
    return s;
}

string solution(ll n, vector<string> bans) {
    vector<ll> spell;
    for(string ban : bans)
        spell.push_back(stringToInt(ban));
    sort(spell.begin(), spell.end());
    for(ll s : spell)
        if(s <= n)
            n++;
    return intToString(n);
}
