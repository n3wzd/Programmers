#include <vector>
using namespace std;
typedef long long ll;
ll w[4001];

ll solution(vector<int> weights) {
    ll answer = 0;
    for(int i : weights)
        w[i]++;
    for(int i = 100; i <= 1000; i++) {
        if(w[i] > 1)
            answer += w[i] * (w[i] - 1) / 2;
        answer += w[i] * w[i * 2];
        if(i % 2 == 0)
            answer += w[i] * w[i / 2 * 3];
        if(i % 3 == 0)
            answer += w[i] * w[i / 3 * 4];
    }
    return answer;
}
