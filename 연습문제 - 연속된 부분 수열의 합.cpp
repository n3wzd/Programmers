#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> S, int K) {
    deque<int> q;
    int sum = 0, N = S.size(), i = 0, lo = 0, hi = N - 1;
    for (int i = 0; i < N;) {
        while (sum < K && i < N) {
            q.push_back(S[i]);
            sum += S[i++];
        }
        while (sum >= K) {
            if (sum == K && (q.size() - 1 < hi - lo))
                lo = i - q.size(), hi = i - 1;
            sum -= q.front();
            q.pop_front();
        }
    }
    return { lo, hi };
}
