#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> targets) {
    int N = targets.size(), answer = 0;
    sort(targets.begin(), targets.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] != b[0] ?  a[0] < b[0] : a[1] > b[1];
    });
    for(int i = 0; i < N;) {
        int lo = targets[i][0], hi = targets[i][1];
        for(i++; i < N; i++) {
            if(!(targets[i][1] <= lo || targets[i][0] >= hi)) {
                lo = max(lo, targets[i][0]);
                hi = min(hi, targets[i][1]);
            }
            else
                break;
        }
        answer++;
    }
    return answer;
}
