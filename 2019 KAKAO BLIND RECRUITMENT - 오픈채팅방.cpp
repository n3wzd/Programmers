#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
map<string, string> m;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    for (auto r : record) {
        istringstream iss(r);
        string a, b, c; iss >> a >> b >> c;
        if (a == "Enter") m[b] = c;
        if (a == "Change") m[b] = c;
    }
    for (auto r : record) {
        istringstream iss(r);
        string a, b; iss >> a >> b;
        if (a == "Enter")
            answer.push_back(m[b] + "님이 들어왔습니다.");
        if (a == "Leave")
            answer.push_back(m[b] + "님이 나갔습니다.");
    }
    return answer;
}
