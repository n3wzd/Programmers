#include <string>
#include <vector>
#include <stack>
#define SIZE 1000001
using namespace std;
bool del[SIZE];
int left[SIZE], right[SIZE];
stack<int> stk;

string solution(int n, int k, vector<string> cmds) {
    int p = k;
    left[0] = right[n - 1] = -1;
    right[0] = 1, left[n - 1] = n - 2;
    for(int i = 1; i < n - 1; i++)
        left[i] = i - 1, right[i] = i + 1;
    for(auto cmd : cmds) {
        if(cmd[0] == 'U' || cmd[0] == 'D') {
            int d = stoi(cmd.substr(2, cmd.size() - 2));
            while(d--)
                p = cmd[0] == 'U' ? left[p] : right[p];
        }
        if(cmd[0] == 'C') {
            del[p] = 1; stk.push(p);
            if(left[p] != -1)
                right[left[p]] = right[p];
            if(right[p] != -1)
                left[right[p]] = left[p];
            p = right[p] != -1 ? right[p] : left[p];
        }
        if(cmd[0] == 'Z') {
            int d = stk.top(); stk.pop();
            del[d] = 0;
            if(left[d] != -1)
                right[left[d]] = d;
            if(right[d] != -1)
                left[right[d]] = d;
        }
    }
    string answer = "";
    for(int i = 0; i < n; i++)
        answer += del[i] ? "X" : "O";
    return answer;
}
