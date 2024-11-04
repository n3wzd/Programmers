#include <string>
#include <vector>
using namespace std;

string reverse(string p) {
    string n = "";
    for (int i = 1; i < p.size() - 1; i++)
        n += p[i] == '(' ? ')' : '(';
    return n;
}

string solve(string p) {
    if (p.size() == 0)
        return p;
    int lCnt = 0, rCnt = 0;
    for (int i = 0; i < p.size(); i++) {
        p[i] == '(' ? lCnt++ : rCnt++;
        if (lCnt == rCnt && lCnt > 0) {
            string u = p.substr(0, i + 1);
            string v = p.substr(i + 1, p.size() - (i + 1));
            if (p[0] == '(')
                return u + solve(v);
            else
                return "(" + solve(v) + ")" + reverse(u);
        }
    }
}

string solution(string p) {
    return solve(p);
}
