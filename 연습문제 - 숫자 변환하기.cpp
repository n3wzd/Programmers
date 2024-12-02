#include <vector>
#include <queue>
using namespace std;
int V[1000001];

int solution(int x, int y, int n) {
    queue<int> q;
    q.push(x); V[x] = 1;
    while(!q.empty()) {
        int c = q.front(); q.pop();
        if(c == y)
            return V[c] - 1;
        int d[] = { c + n, c * 2, c * 3 };
        for(int i = 0; i < 3; i++) {
            if(d[i] <= y && V[d[i]] == 0) {
                q.push(d[i]);
                V[d[i]] = V[c] + 1;
            }
        }
    }
    return -1;
}
