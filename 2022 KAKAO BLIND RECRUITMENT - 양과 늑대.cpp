#include <vector>
using namespace std;
vector<int> graph[18], info;
int N, level[18], tmpSheep, tmpNext, res = 1;

void setLevel(int n, int d) {
    level[n] = d;
    for (int next : graph[n])
        if (level[next] == 0)
            setLevel(next, d + 1);
}

void DFS(int cur, int start) {
    if (info[cur] && cur != start) {
        tmpNext |= 1 << cur;
        return;
    }
    if (!info[cur])
        tmpSheep++;
    for (int next : graph[cur])
        if (level[cur] < level[next])
            DFS(next, start);
}

void BT(int sheep, int wolf, int start, int next) {
    tmpNext = next, tmpSheep = 0;
    DFS(start, start);
    next = tmpNext, sheep += tmpSheep;
    res = max(res, sheep);
    for (int i = 0; i <= N; i++) {
        if (next & (1 << i) && sheep > wolf + 1)
            BT(sheep, wolf + 1, i, next & ~(1 << i));
    }
}

int solution(vector<int> infoI, vector<vector<int>> edges) {
    info = infoI;
    for (auto edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
        N = max(N, max(edge[0], edge[1]));
    }
    setLevel(0, 1);
    BT(0, 0, 0, 0);
    return res;
}
