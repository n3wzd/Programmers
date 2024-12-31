#include <vector>
using namespace std;
vector<int> D[3] = {{1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
int cnt[3], maxScore = 0;

vector<int> solution(vector<int> answers) {
    vector<int> solution;
    for(int i = 0; i < answers.size(); i++)
        for(int d = 0; d < 3; d++)
            cnt[d] += answers[i] == D[d][i % D[d].size()] ? 1 : 0;
    for(int d = 0; d < 3; d++)
        maxScore = max(maxScore, cnt[d]);
    for(int d = 0; d < 3; d++)
        if(cnt[d] == maxScore)
            solution.push_back(d + 1);
    return solution;
}
