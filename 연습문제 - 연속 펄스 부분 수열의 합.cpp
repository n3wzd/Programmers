#include <vector>
using namespace std;
typedef long long ll;

ll solve(vector<int> S) {
    ll sum = 0, res = 0;
    for(auto n : S) {
        sum = -n < sum ? sum + n : 0;
        res = max(res, sum);
    }
    return res;
}

ll solution(vector<int> S) {
    vector<int> A, B;
    for(int i = 0; i < S.size(); i++) {
        A.push_back(S[i] * (i % 2 == 0 ? -1 : 1));
        B.push_back(S[i] * (i % 2 == 1 ? -1 : 1));
    }
    return max(solve(A), solve(B));
}
