#include <vector>
using namespace std;
int dt[50], answer, cnt;

int solution(vector<int> players, int m, int k) {
    for(int i = 0; i < 24; i++) {
        int p = players[i] / m;
        cnt -= dt[i];
        if(cnt < p) {
            dt[i + k] += p - cnt;
            answer += p - cnt;
            cnt = p;
        }
    }
    return answer;
}
