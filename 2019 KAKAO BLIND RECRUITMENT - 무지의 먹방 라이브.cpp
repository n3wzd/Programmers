#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

int solution(vector<int> food_times, ll k) {
    map<int, int> cntMap; vector<vector<int>> cnt;
    for (int food : food_times)
        cntMap[food] ? cntMap[food]++ : cntMap[food] = 1;
    for (const auto& pair : cntMap)
        cnt.push_back({ pair.first, pair.second });
    sort(cnt.begin(), cnt.end(), [](const vector<int>& s1, const vector<int>& s2) {
        return s1[0] < s2[0];
        });
    ll prevFood = 0, foodLen = food_times.size();
    for (auto c : cnt) {
        ll eat = foodLen * (c[0] - prevFood);
        if (k < eat) {
            ll idx = k % foodLen, res = 1;
            for (int food : food_times) {
                if (food > prevFood)
                    if (idx-- == 0)
                        return res;
                res++;
            }
        }
        k -= eat;
        foodLen -= c[1], prevFood = c[0];
    }
    return -1;
}
