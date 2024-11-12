#include <vector>
#include <queue>
using namespace std;
deque<int> q;

int solution(vector<int> stones, int k) {
    int answer = 1 << 30;
    for (int i = 0; i < stones.size(); i++) {
        while (!q.empty() && stones[q.front()] <= stones[i])
            q.pop_front();
        q.push_front(i);
        if (i >= k && q.back() == i - k)
            q.pop_back();
        if (i >= k - 1)
            answer = min(answer, stones[q.back()]);
    }
    return answer;
}
