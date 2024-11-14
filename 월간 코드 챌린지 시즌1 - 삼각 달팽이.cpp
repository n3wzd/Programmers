#include <vector>
using namespace std;
int tri[1001][1001];
vector<int> answer;
int dx[3] = { 0, 1, -1 }, dy[3] = { 1, 0, -1 };

void init(int n) {
    int x = 0, y = -1, genID = 1;
    for (int t = n; t > 0; t--) {
        for (int k = 0; k < t; k++) {
            x += dx[(n - t) % 3], y += dy[(n - t) % 3];
            tri[y][x] = genID++;
        }
    }
}

vector<int> solution(int n) {
    init(n);
    for (int y = 0; y < n; y++)
        for (int x = 0; x <= y; x++)
            answer.push_back(tri[y][x]);
    return answer;
}
