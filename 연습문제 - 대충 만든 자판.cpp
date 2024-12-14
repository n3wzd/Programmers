#include <string>
#include <vector>
using namespace std;
const int INF = 100001;
vector<int> key(26, INF);

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    for(auto k : keymap)
        for(int i = 0; i < k.size(); i++)
            key[k[i] - 'A'] = min(i + 1, key[k[i] - 'A']);
    for(auto s : targets) {
        int cnt = 0;
        for(auto c : s)
            cnt += key[c - 'A'];
        answer.push_back(cnt >= INF ? -1 : cnt);
    }
    return answer;
}
