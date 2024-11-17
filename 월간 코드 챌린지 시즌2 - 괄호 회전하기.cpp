#include <string>
#include <vector>
#include <stack>
using namespace std;
char match(char c) {
    if(c == ')') return '(';
    if(c == '}') return '{';
    if(c == ']') return '[';
    return ' ';
}

int solution(string s) {
    int answer = 0, N = s.size();
    for(int b = 0; b < N; b++) {
        stack<char> stk;
        for(int i = 0; i < N; i++) {
            char cur = s[(b + i) % N];
            if(!stk.empty() && stk.top() == match(cur))
                stk.pop();
            else
                stk.push(cur);
        }
        if(stk.empty())
            answer++;
    }
    return answer;
}
