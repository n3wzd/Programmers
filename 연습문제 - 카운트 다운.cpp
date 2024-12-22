#include <vector>
#include <queue>
using namespace std;
struct Node { int v, w, s; };
struct cmp { bool operator()(Node& a, Node& b) { return (a.w != b.w) ? a.w > b.w : a.s < b.s; } };
priority_queue<Node, vector<Node>, cmp> pq;
vector<int> dist[100001];
const int INF = 1e9;

void update(int nv, int nw, int ns, int target) {
    if(nv > target)
        return;
    if(dist[nv][0] > nw || (dist[nv][0] == nw && dist[nv][1] < ns)) {
        dist[nv] = { nw, ns };
        pq.push({ nv, nw, ns });
    }
}

vector<int> solution(int target) {
    for (int i = 1; i <= target; i++)
        dist[i] = { INF, 0 };
    pq.push({ 0, 0, 0 });
    while (!pq.empty()) {
        auto node = pq.top(); pq.pop();
        int v = node.v, w = node.w, s = node.s;
        if(v == target)
            return { w, s };
        update(v + 50, w + 1, s + 1, target);
        for(int m = 1; m <= 3; m++)
            for(int n = 1; n <= 20; n++)
                update(v + n * m, w + 1, s + (m == 1 ? 1 : 0), target);
    }
    return { INF, INF };
}
