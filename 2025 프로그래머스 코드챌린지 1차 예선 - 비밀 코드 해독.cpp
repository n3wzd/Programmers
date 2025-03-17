#include <vector>
using namespace std;
vector<vector<int>> q;
vector<int> ans;
int N, arr[5], answer;

int hasN(int n) {
    for(int i = 0; i < 5; i++)
        if(arr[i] == n)
            return 1;
    return 0;
}

void combination(int d = 0, int s = 1) {
    if(d == 5) {
        bool ok = 1;
        for(int i = 0; i < q.size(); i++) {
            int cnt = 0;
            for(int n : q[i])
                cnt += hasN(n);
            ok &= cnt == ans[i];
        }
        if(ok)
            answer++;
        return;
    }
    for(int i = s; i <= N; i++) {
        arr[d] = i;
        combination(d + 1, i + 1);
    }
}

int solution(int n, vector<vector<int>> Q, vector<int> ANS) {
    N = n, ans = ANS, q = Q; combination();
    return answer;
}
