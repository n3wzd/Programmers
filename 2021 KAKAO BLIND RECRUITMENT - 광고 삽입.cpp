#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
ll width, N, sum, resSum, resLo, dt, dtx[360001];
ll ttoi(string t) {
    return stoi(t.substr(0, 2)) * 3600 + stoi(t.substr(3, 2)) * 60 + stoi(t.substr(6, 2));
}
string itot(ll t) {
    stringstream h, m, s;
    h << setw(2) << setfill('0') << to_string(t / 3600);
    m << setw(2) << setfill('0') << to_string((t % 3600) / 60);
    s << setw(2) << setfill('0') << to_string(t % 60);
    return h.str() + ":" + m.str() + ":" + s.str();
}

string solution(string play_time, string adv_time, vector<string> logs) {
    N = ttoi(play_time), width = ttoi(adv_time) - 1;
    for (auto log : logs) {
        dtx[ttoi(log.substr(0, 8))]++;
        dtx[ttoi(log.substr(9, 8))]--;
    }
    for (ll i = 0; i < width; i++)
        dt += dtx[i], sum += dt;
    for (ll lo = 0; lo <= N - width; lo++) {
        dt += dtx[lo + width];
        sum += dt;
        if (sum > resSum)
            resSum = sum, resLo = lo;
        dt -= dtx[lo];
    }
    return itot(resLo);
}
