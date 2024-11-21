#include <string>
#include <vector>
using namespace std;

vector<string> solution(vector<string> list) {
    vector<string> answer;
    for (auto s : list) {
        string stk; int cnt = 0;
        for(int i = 0; i < s.size(); i++) {
            stk += s[i];
            int N = stk.size();
            if(N > 2 && stk.substr(N - 3, 3) == "110") {
                stk.erase(N - 3);
                cnt++;
            }
        }
        int N = stk.size(), p;
        string group = "";
        for(p = N - 1; p >= 0; p--)
            if(stk[p] == '0')
                break;
        while(cnt--)
            group += "110";
        stk.insert(p + 1, group);
        answer.push_back(stk);
    }
    return answer;
}
