#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int minN = 1001;
    for (int d = 1; d <= s.size() / 2; d++) {
        vector<string> token;
        for (int t = 0; t < s.size(); t += d)
            token.push_back(t + d < s.size() ? s.substr(t, d) : s.substr(t, s.size() - t));
        int combo = 1, res = 0;
        for (int i = 0; i < token.size() - 1; i++) {
            if (token[i] == token[i + 1])
                combo++;
            else {
                res += (combo > 1 ? to_string(combo).size() : 0) + d;
                combo = 1;
            }
        }
        res += combo > 1 ? to_string(combo).size() + d : token[token.size() - 1].size();
        minN = min(minN, res);
    }
    return s.size() == 1 ? 1 : minN;
}
