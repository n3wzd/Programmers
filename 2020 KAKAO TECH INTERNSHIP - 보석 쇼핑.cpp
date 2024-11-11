#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> cnt;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    for (auto gem : gems)
        cnt[gem] == 0 ? cnt[gem] = 1 : cnt[gem]++;

    int lo = 0, hi = gems.size() - 1;
    while (cnt[gems[hi]] > 1)
        cnt[gems[hi--]]--;
    while (cnt[gems[lo]] > 1)
        cnt[gems[lo++]]--;
    int minLen = hi - lo;
    answer = { lo + 1, hi + 1 };

    while (lo < hi && hi < gems.size()) {
        while (hi < gems.size() - 1 && gems[hi] != gems[lo])
            cnt[gems[++hi]]++;
        if (gems[hi] != gems[lo])
            break;
        while (cnt[gems[lo]] > 1)
            cnt[gems[lo++]]--;
        if (hi - lo < minLen) {
            minLen = hi - lo;
            answer = { lo + 1, hi + 1 };
        }
    }
    return answer;
}
