#include <string>
#include <vector>
using namespace std;

bool Cond(int level, vector<int> diffs, vector<int> times, long long limit) {
    int size = diffs.size();
    long long gameTime = 0;
    for (int i = 0; i < size; i++)
        gameTime += level >= diffs[i] ? times[i] : (diffs[i] - level) * (times[i] + times[i - 1]) + times[i];
    return gameTime <= limit;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int lo = 1, hi = 100000, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (Cond(mid, diffs, times, limit)) hi = mid;
        else lo = mid + 1;
    }
    return hi;
}
