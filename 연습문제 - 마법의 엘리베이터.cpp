#include <vector>
using namespace std;

int answer = 2e9;
void BT(int n, int cnt) {
    if(n < 10) {
        cnt += n <= 5 ? n : 11 - n;
        answer = min(answer, cnt);
        return;
    }
    BT(n / 10, cnt + (n % 10));
    BT(n / 10 + 1, cnt + (10 - n % 10));
}

int solution(int n) {
    BT(n, 0);
    return answer;
}
