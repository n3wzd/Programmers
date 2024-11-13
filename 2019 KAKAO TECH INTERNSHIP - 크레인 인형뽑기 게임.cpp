#include <vector>
#include <stack>
using namespace std;
stack<int> stk;

int solution(vector<vector<int>> board, vector<int> moves) {
    int N = board.size(), answer = 0;
    for (auto x : moves) {
        int y = 0; x--;
        while (y < N && board[y][x] == 0) y++;
        if (y < N) {
            if (!stk.empty() && stk.top() == board[y][x]) {
                stk.pop();
                answer += 2;
            }
            else
                stk.push(board[y][x]);
            board[y][x] = 0;
        }
    }
    return answer;
}
