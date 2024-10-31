#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;
map<string, int> m;
int cnt[1001], genID;
bool cert[1001][1001];

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    for (auto s : id_list)
        m.insert({ s, genID++ });
    for (auto r : report) {
        istringstream iss(r);
        string a, b; iss >> a >> b;
        int user1 = m.find(a)->second, user2 = m.find(b)->second;
        if (!cert[user1][user2]) {
            cert[user1][user2] = 1;
            cnt[user2]++;
        }
    }
    for (auto r : id_list) {
        int mail = 0, user = m.find(r)->second;
        for (int i = 0; i < id_list.size(); i++)
            if (cert[user][i] && cnt[i] >= k)
                mail++;
        answer.push_back(mail);
    }
    return answer;
}
