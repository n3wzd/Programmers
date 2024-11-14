#include <vector>
using namespace std;

int solution(vector<int> a) {
    int minV = 1e9 + 1, answer = 1, N = a.size();
    for (auto n : a)
        minV = min(minV, n);
    int lo = 1e9 + 1, hi = 1e9 + 1;
    for (int i = 0; a[i] != minV; i++)
        if (a[i] < lo)
            answer++, lo = a[i];
    for (int i = N - 1; a[i] != minV; i--)
        if (a[i] < hi)
            answer++, hi = a[i];
    return answer;
}
