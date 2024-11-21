#include <cmath>
using namespace std;

int find(int n) {
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        if(n % i == 0)
            cnt++;
    return cnt;
}

int solution(int left, int right) {
    int answer = 0;
    for(int n = left; n <= right; n++)
        answer += find(n) % 2 == 0 ? n : -n;
    return answer;
}
