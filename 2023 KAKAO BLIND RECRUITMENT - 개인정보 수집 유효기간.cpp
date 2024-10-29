#include <string>
#include <vector>
using namespace std;
int priv[27];
int timeToInt(string s) {
    return (stoi(s.substr(0, 4)) * 12 + stoi(s.substr(5, 2))) * 28 + stoi(s.substr(8, 2));
}

vector<int> solution(string todayS, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int today = timeToInt(todayS);
    for (string s : terms)
        priv[s[0] - 65] = stoi(s.substr(2, s.size() - 2)) * 28;
    for (int i = 0; i < privacies.size(); i++) {
        string s = privacies[i];
        int t = timeToInt(s.substr(0, 10));
        int d = priv[s[s.size() - 1] - 65];
        if (today >= t + d)
            answer.push_back(i + 1);
    }
    return answer;
}
