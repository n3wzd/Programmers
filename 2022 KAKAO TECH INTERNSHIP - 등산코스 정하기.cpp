#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 50001;
int type[MAXN], parent[MAXN], intensity, summit = MAXN;

int find(int n) {
    int p = n;
    while (parent[p] >= 0) p = parent[p];
    if (parent[n] >= 0) parent[n] = p;
    return p;
}

int merge(int a, int b) {
    int p1 = find(a);
    int p2 = find(b);
    if (p1 == p2 || type[p1] + type[p2] == 4 || (type[p1] == 1 && type[p2] == 1))
        return MAXN;

    if (type[p1] + type[p2] == 3)
        return type[p1] == 2 ? p1 : p2;
    else if (type[p1] == 1 || type[p1] == 2)
        parent[p2] = p1;
    else
        parent[p1] = p2;
    return MAXN;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    for (int i = 0; i <= n; i++)
        parent[i] = -1;
    for (int gate : gates)
        type[gate] = 1;
    for (int sum : summits)
        type[sum] = 2;
    sort(paths.begin(), paths.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
        });
    intensity = paths[0][2];
    for (int p = 0; p < paths.size(); p++) {
        if (intensity != paths[p][2] && summit != MAXN)
            break;
        intensity = paths[p][2];
        summit = min(summit, merge(paths[p][0], paths[p][1]));
    }
    return { summit, intensity };
}
