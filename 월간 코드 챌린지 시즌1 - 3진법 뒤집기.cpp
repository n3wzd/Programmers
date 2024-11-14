#include <vector>
using namespace std;
vector<int> T;

int solution(int n) {
    while (n > 0) {
        T.push_back(n % 3);
        n /= 3;
    }
    int answer = 0, N = T.size();
    for (int i = N - 1, d = 1; i >= 0; i--, d *= 3)
        answer += T[i] * d;
    return answer;
}
