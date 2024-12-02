#include <vector>
using namespace std;
int x1, y1, INF = 1e9;
int dist(int ax, int ay, int bx, int by) { return (ax - bx) * (ax - bx) + (ay - by) * (ay - by); }
int D(int x2, int y2, int x3, int y3) { 
    return ((x1 == x3 || y1 == y3) && dist(x1, y1, x3, y3) > dist(x2, y2, x3, y3)) ? INF : dist(x1, y1, x3, y3);
}

vector<int> solution(int m, int n, int X1, int Y1, vector<vector<int>> balls) {
    vector<int> answer; x1 = X1, y1 = Y1;
    for(auto b : balls) {
        int d = INF, a[4][2] = { { -b[0], b[1] }, { b[0], -b[1] }, { m + m - b[0], b[1] }, { b[0], n + n - b[1] } };
        for(int i = 0; i < 4; i++)
            d = min(d, D(b[0], b[1], a[i][0], a[i][1]));
        answer.push_back(d);
    }
    return answer;
}
