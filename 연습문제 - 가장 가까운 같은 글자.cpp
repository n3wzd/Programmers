#include <string>
#include <vector>
using namespace std;
vector<int> p(26, -1);

vector<int> solution(string s) {
    vector<int> answer;
    for(int i = 0; i < s.size(); i++) {
        answer.push_back(p[s[i] - 'a'] == -1 ? -1 : i - p[s[i] - 'a']);
        p[s[i] - 'a'] = i;
    }
    return answer;
}
