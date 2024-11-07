#include <string>
#include <vector>
using namespace std;
bool flag[31][31];

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while (1) {
        for (int y = 0; y < m - 1; y++)
            for (int x = 0; x < n - 1; x++)
                if (board[y][x] == board[y + 1][x] && board[y][x] == board[y][x + 1]
                    && board[y][x] == board[y + 1][x + 1] && board[y][x] != '.')
                    flag[y][x] = flag[y + 1][x] = flag[y][x + 1] = flag[y + 1][x + 1] = 1;
        bool isEnd = 1;
        for (int y = 0; y < m; y++)
            for (int x = 0; x < n; x++)
                if (flag[y][x])
                    board[y][x] = '.', answer++, isEnd = 0, flag[y][x] = 0;
        if (isEnd)
            return answer;
        for (int y = m - 1; y >= 0; y--) {
            for (int x = 0; x < n; x++) {
                int ty = y;
                while (ty < m - 1 && board[ty + 1][x] == '.') ty++;
                if (y != ty) {
                    board[ty][x] = board[y][x];
                    board[y][x] = '.';
                }
            }
        }
    }
}
