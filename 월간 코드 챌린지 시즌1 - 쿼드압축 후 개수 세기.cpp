#include <vector>
using namespace std;
vector<vector<int>> arr;
int cnt[2];

void quad(int x, int y, int d) {
    bool ok = 1;
    for (int dy = 0; dy < d; dy++)
        for (int dx = 0; dx < d; dx++)
            ok &= arr[y][x] == arr[y + dy][x + dx];
    if (ok) {
        cnt[arr[y][x]]++;
        return;
    }
    int nd = d / 2;
    quad(x, y, nd);
    quad(x + nd, y, nd);
    quad(x, y + nd, nd);
    quad(x + nd, y + nd, nd);
}

vector<int> solution(vector<vector<int>> arrI) {
    arr = arrI; quad(0, 0, arr.size());
    return { cnt[0], cnt[1] };
}
