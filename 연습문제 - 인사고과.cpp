#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> S) {
    int maxY = -1, curX = -1, nextMaxY = -1;
    vector<vector<int>> T; vector<int> my = S[0];
    sort(S.begin(), S.end(), [](auto a, auto b) { 
        return a[0] != b[0] ? a[0] > b[0] : a[1] > b[1];
    });
    for(auto n : S) {
        if(n[0] != curX) {
            curX = n[0];
            maxY = nextMaxY;
            nextMaxY = max(nextMaxY, n[1]);
        }
        if(n[1] >= maxY)
            T.push_back(n);
    }
    
    int psum = 1e9, rank = 0, answer = -1;
    sort(T.begin(), T.end(), [](auto a, auto b) { return a[0] + a[1] > b[0] + b[1]; });
    for(int i = 0; i < T.size(); i++) {
        auto n = T[i];
        if(psum > n[0] + n[1])
            psum = n[0] + n[1], rank = i + 1;
        if(n[0] == my[0] && n[1] == my[1])
            answer = rank;
    }
    return answer;
}
