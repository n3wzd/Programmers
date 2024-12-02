#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
struct Node { string id; int s, d; };
int ttoi(string s) { return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2)); }
stack<Node> stk;
vector<Node> P;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    for(auto p : plans)
        P.push_back({p[0], ttoi(p[1]), stoi(p[2])});
    sort(P.begin(), P.end(), [](Node &a, Node &b) { return a.s < b.s; });
    for(auto p : P) {
        while(!stk.empty() && stk.top().s + stk.top().d <= p.s) {
            Node cur = stk.top(); stk.pop();
            answer.push_back(cur.id);
            if(!stk.empty())
                stk.top().s = cur.s + cur.d;
        }
        if(!stk.empty())
            stk.top().d -= p.s - stk.top().s;
        stk.push(p);
    }
    while(!stk.empty())
        answer.push_back(stk.top().id), stk.pop();
    return answer;
}
