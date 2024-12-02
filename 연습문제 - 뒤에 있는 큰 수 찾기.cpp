#include <stack>
#include <vector>
using namespace std;
struct Node { int n, i; };
stack<Node> stk;

vector<int> solution(vector<int> L) {
    int N = L.size(); vector<int> answer(N, 0);
    for(int i = 0; i < N; i++) {
        while(!stk.empty() && stk.top().n < L[i])
            answer[stk.top().i] = L[i], stk.pop();
        stk.push({ L[i], i });
    }
    while(!stk.empty())
        answer[stk.top().i] = -1, stk.pop();
    return answer;
}
