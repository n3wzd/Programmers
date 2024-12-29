#include <vector>
#include <cmath>
using namespace std;

int D(int n) {
    int cnt = 0, s = sqrt(n);
    for(int i = 1; i <= s; i++)
        if(n % i == 0)
            cnt += (i == s && s * s == n ? 1 : 2);
    return cnt;
}

int solution(int N, int L, int P) {
    int answer = 0;
    for(int i = 1; i <= N; i++) {
        int d = D(i);
        answer += d > L ? P : d;
    }
    return answer;
}
