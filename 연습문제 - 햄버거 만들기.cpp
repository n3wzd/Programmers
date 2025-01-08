#include <vector>
using namespace std;

int solution(vector<int> A) {
    vector<int> S;
    int answer = 0;
    for(int a : A) {
        S.push_back(a);
        int s = S.size();
        if(s > 3 && S[s - 1] == 1 && S[s - 2] == 3 && S[s - 3] == 2 && S[s - 4] == 1) {
            answer++;
            for(int r = 0; r < 4; r++)
                S.pop_back();
        }
    }
    return answer;
}
