#include <vector>
using namespace std;
int DP[1001][51];
const int INF = 1e9;

int solution(int T, int T1, int T2, int CA, int CB, vector<int> B) {
    int N = B.size(), answer = INF; T += 10, T1 += 10, T2 += 10;
    for(int b = 0; b < N; b++)
        for(int t = 0; t <= 50; t++)
            DP[b][t] = INF;
    DP[0][T] = 0;
    for(int b = 1; b < N; b++) {
        for(int t = 0; t <= 50; t++) {
            if(B[b] == 1 && (t < T1 || t > T2))
                continue;
            DP[b][t] = DP[b - 1][t] + (t == T ? 0 : CB);
            if(t > 0)
                DP[b][t] = min(DP[b][t], DP[b - 1][t - 1] + (t <= T ? 0 : CA));
            if(t < 50)
                DP[b][t] = min(DP[b][t], DP[b - 1][t + 1] + (t >= T ? 0 : CA));
        }
    }
    for(int t = 0; t <= 50; t++)
        answer = min(answer, DP[N - 1][t]);
    return answer;
}
