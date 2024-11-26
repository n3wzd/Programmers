#include <string>
#include <stack>
using namespace std;

int solution(string s) {
    stack<char> stk;
    for(auto c : s)
        !stk.empty() && stk.top() == c ? stk.pop() : stk.push(c);
    return stk.empty() ? 1 : 0;
}
