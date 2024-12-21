#include <stack>
#include <vector>
using namespace std;

int solution(vector<int> order) {
    int answer = 0, N = order.size();
    stack<int> stk;
    for(int i = 0; i < N; i++) {
        stk.push(i + 1);
        while(!stk.empty() && stk.top() == order[answer])
            stk.pop(), answer++;
    }
    return answer;
}
