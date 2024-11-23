#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll solution(vector<vector<int>> land2D, int P, int Q) {
    ll answer = ((ll)1 << 62), p = 0, q = 0, k = 1;
    vector<int> land;
    for(auto row : land2D)
        for(auto c : row)
            land.push_back(c);
    sort(land.begin(), land.end());
    
    ll N = land.size(), fisrt = land[0];
    for(int& block : land)
        block -= fisrt, q += block;
    for(int i = 0; i < N - 1; i++) {
        answer = min(answer, p * P + q * Q);
        ll dist = land[i + 1] - land[i];
        p += k * dist, q -= (N - k) * dist, k++;
    }
    answer = min(answer, p * P + q * Q);
    return answer;
}
