#include <vector>
using namespace std;
int answer;

void install(int lo, int hi, int W) {
    if(lo < hi) {
        int dist = hi - lo, wide = W * 2 + 1;
        answer += dist / wide + (dist % wide != 0 ? 1 : 0);
    }
}

int solution(int N, vector<int> S, int W) {
    int lo = 1;
    for(int i = 0; i < S.size(); i++) {
        install(lo, S[i] - W, W);
        lo = S[i] + W + 1;
    }
    install(lo, N + 1, W);
    return answer;
}
