#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> P, vector<int> S) {
    vector<int> answer, C;
    for(int i = 0; i < P.size(); i++) {
        int d = (100 - P[i]) / S[i];
        C.push_back(d * S[i] == 100 - P[i] ? d : d + 1);
    }
    int mx = C[0], p = 0;
    for(int i = 1; i < P.size(); i++) {
        if(C[i] > mx) {
            mx = C[i];
            answer.push_back(i - p);
            p = i;
        }
    }
    answer.push_back(P.size() - p);
    return answer;
}
