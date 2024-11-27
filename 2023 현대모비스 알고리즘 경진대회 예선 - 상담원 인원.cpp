#include <vector>
#include <queue>
using namespace std;
int N, K, answer = 1e9;
vector<int> selected;
vector<vector<int>> R;

void combination(int start, int depth) {
    if (depth == K - 1) {
        priority_queue<int, vector<int>, greater<int>> pq[5];
        int mento[5] = { selected.size() > 0 ? selected[0] : N, }, wait = 0;
        for (int i = 1; i < K - 1; i++)
            mento[i] = selected[i] - selected[i - 1];
        if (K > 1)
            mento[K - 1] = N - selected[K - 2];
        for (int i = 0; i < K; i++)
            for (int p = 0; p < mento[i]; p++)
                pq[i].push(0);
        for (auto r : R) {
            int s = pq[r[2] - 1].top(); pq[r[2] - 1].pop();
            wait += s - r[0] > 0 ? s - r[0] : 0;
            pq[r[2] - 1].push(max(s, r[0]) + r[1]);
        }
        answer = min(answer, wait);
        return;
    }
    for (int i = start; i < N; i++) {
        selected.push_back(i);
        combination(i + 1, depth + 1);
        selected.pop_back();
    }
}

int solution(int k, int n, vector<vector<int>> reqs) {
    N = n, K = k, R = reqs;
    combination(1, 0);
    return answer;
}
