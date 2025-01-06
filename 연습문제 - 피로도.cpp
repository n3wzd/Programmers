#include <vector>
using namespace std;
vector<vector<int>> D;
int N; bool selected[9];

int BT(int depth, int coffee) {
    if(depth == 0)
        return 0;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(selected[i])
            continue;
        selected[i] = 1;
        if(coffee >= D[i][0] && coffee >= D[i][1])
            cnt = max(cnt, BT(depth - 1, coffee - D[i][1]) + 1);
        selected[i] = 0;
    }
    return cnt;
}

int solution(int k, vector<vector<int>> dungeons) {
    D = dungeons; N = D.size();
    return BT(N, k);
}
