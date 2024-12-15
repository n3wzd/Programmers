#include <vector>
using namespace std;
const int MAXN = 5000001;
int D[MAXN] = { 0, 1, }, M[MAXN], X[MAXN];

void divisor(int e) {
    for(int a = 2; a <= e; a++)
        for(int i = 1; a * i <= e; i++)
            D[a * i]++;
}

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer; divisor(e); int m = MAXN;
    for(int s : starts)
        m = min(s, m);
    M[e] = D[e]; X[e] = e;
    for(int i = e - 1; i >= m; i--) {
        X[i] = M[i + 1] <= D[i] ? i : X[i + 1];
        M[i] = max(M[i + 1], D[i]);
    }
    for(int s : starts)
        answer.push_back(X[s]);
    return answer;
}
