#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto c : commands) {
        vector<int> sub;
        for (int i = c[0] - 1; i <= c[1] - 1; i++)
            sub.push_back(array[i]);
        sort(sub.begin(), sub.end());
        answer.push_back(sub[c[2] - 1]);
    }
    return answer;
}
