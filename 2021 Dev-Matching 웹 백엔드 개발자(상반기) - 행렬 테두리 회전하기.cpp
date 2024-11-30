#include <vector>
using namespace std;
int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
int A[101][101], T[101][101];

vector<int> solution(int N, int M, vector<vector<int>> Q) {
    vector<int> answer;
    for(int i = 0; i < N * M; i++)
        A[i / M][i % M] = i + 1;
    for(auto q : Q) {
        int x1 = q[1] - 1, y1 = q[0] - 1, x2 = q[3] - 1, y2 = q[2] - 1;
        int hd = x2 - x1, vd = y2 - y1, m = N * M + 1;
        int s[4][2] = { {x1, y1}, {x2, y1}, {x2, y2}, {x1, y2} };
        for(int d = 0; d < 4; d++)
            for(int i = 0; i < (d % 2 == 0 ? hd : vd); i++)
                T[s[d][1] + dy[d] * (i + 1)][s[d][0] + dx[d] * (i + 1)] = A[s[d][1] + dy[d] * i][s[d][0] + dx[d] * i];
        for(int d = 0; d < 4; d++)
            for(int i = 0; i <= (d % 2 == 0 ? hd : vd); i++)
                m = min(m, A[s[d][1] + dy[d] * i][s[d][0] + dx[d] * i] = T[s[d][1] + dy[d] * i][s[d][0] + dx[d] * i]);
        answer.push_back(m);
    }
    return answer;
}
