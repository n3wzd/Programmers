#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
queue<int> q1, q2;
int N, mv1, mv2; ll sum1, sum2 = 0;

int solution(vector<int> queue1, vector<int> queue2) {
    N = queue1.size();
    for (int n : queue1) sum1 += n, q1.push(n);
    for (int n : queue2) sum2 += n, q2.push(n);
    while (mv1 < N || mv2 < N) {
        if (sum1 == sum2)
            return mv1 + mv2;
        else if (sum1 < sum2) {
            int n = q2.front(); q2.pop();
            sum1 += n; sum2 -= n; mv2++;
            q1.push(n);
        }
        else {
            int n = q1.front(); q1.pop();
            sum2 += n; sum1 -= n; mv1++;
            q2.push(n);
        }
    }
    return -1;
}
