#include <string>
#include <vector>
using namespace std;
const int INF = 1e6;
int DP[20001];
string S;

bool cmp(string tk, int hi) {
    for(int i = 0; i < tk.size(); i++)
        if(S[hi - tk.size() + i] != tk[i])
            return 0;
    return 1;
}

int solution(vector<string> strs, string t) {
    S = t; int N = S.size();
    for(int n = 1; n <= N; n++) {
        DP[n] = INF;
        for(auto tk : strs)
            if(n >= tk.size() && S[n - 1] == tk.back() && cmp(tk, n))
                DP[n] = min(DP[n], DP[n - tk.size()] + 1);
    }
    return DP[N] == INF ? -1 : DP[N];
}
