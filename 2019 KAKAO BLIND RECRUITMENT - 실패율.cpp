#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
struct Stage { ll id, a, b; };
vector<Stage> stages; vector<int> answer;

vector<int> solution(int N, vector<int> clears) {
    sort(clears.begin(), clears.end());
    for (int i = 1; i <= N; i++) {
        auto low = lower_bound(clears.begin(), clears.end(), i);
        auto upp = upper_bound(clears.begin(), clears.end(), i);
        ll a = distance(low, clears.end()), b = distance(low, upp);
        if (a > 0 && b > 0)
            stages.push_back({ i, a, b });
        else
            stages.push_back({ i, 1, -1 });
    }
    sort(stages.begin(), stages.end(), [](const auto& x, const auto& y) {
        return x.a * y.b == y.a * x.b ? x.id < y.id : x.a * y.b < y.a * x.b;
        });
    for (auto s : stages)
        answer.push_back(s.id);
    return answer;
}
