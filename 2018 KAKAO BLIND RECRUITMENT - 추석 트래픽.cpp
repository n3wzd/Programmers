#include <string>
#include <vector>
using namespace std;
struct Range { int lo, hi; };
int ttoi(string t) {
    return stoi(t.substr(11, 2)) * 3600000 + stoi(t.substr(14, 2)) * 60000 +
        stoi(t.substr(17, 2)) * 1000 + stoi(t.substr(20, 3));
}

int solution(vector<string> logs) {
    vector<Range> R;
    for (auto log : logs) {
        int hi = ttoi(log);
        int lo = hi - stod(log.substr(24, log.size() - 25)) * 1000;
        R.push_back({ lo + 1, hi });
    }
    int maxCnt = 1, N = R.size();
    for (int i = 0; i < N; i++) {
        int cnt1 = 0, cnt2 = 0;
        for (int j = 0; j < N; j++) {
            if (!(R[j].lo > R[i].lo + 999 || R[j].hi < R[i].lo))
                cnt1++;
            if (!(R[j].lo > R[i].hi + 999 || R[j].hi < R[i].hi))
                cnt2++;
        }
        maxCnt = max(maxCnt, max(cnt1, cnt2));
    }
    return maxCnt;
}
