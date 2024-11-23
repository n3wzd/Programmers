#include <vector>
using namespace std;
int DP[100001][2];

int solution(vector<int> sticker) {
    int N = sticker.size();
    for(int i = 0; i < 2; i++) {
        DP[0][i] = i == 0 ? sticker[0] : 0;
        DP[1][i] = max(DP[0][i], sticker[1]);
        for(int n = 2; n < N - 1; n++)
            DP[n][i] = max(DP[n - 1][i], DP[n - 2][i] + sticker[n]);
        DP[N - 1][i] = max(DP[N - 2][i], i == 0 ? 0 : DP[N - 3][i] + sticker[N - 1]);
    }
    return max(DP[N - 1][0], DP[N - 1][1]);
}
