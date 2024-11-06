#include <vector>
#include <algorithm>
using namespace std;
struct Node { int x, id; };
vector<int> graph[10002];
vector<Node> nodeY[100001];
vector<vector<int>> answer = { {}, {} };

void makeTree(int lo, int hi, int x, int y, int parent) {
    while (y >= 0 && nodeY[y].size() == 0) y--;
    if (y < 0) return;
    for (auto node : nodeY[y]) {
        if (node.x > lo && node.x < hi) {
            graph[parent].push_back(node.id);
            if (node.x < x)
                makeTree(lo, x, node.x, y - 1, node.id);
            else
                makeTree(x, hi, node.x, y - 1, node.id);
        }
    }
}

void preorder(int n) {
    if (n != 0) answer[0].push_back(n);
    for (auto next : graph[n])
        preorder(next);
}

void postorder(int n) {
    for (auto next : graph[n])
        postorder(next);
    if (n != 0) answer[1].push_back(n);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    int genID = 1;
    for (auto p : nodeinfo)
        nodeY[p[1]].push_back({ p[0], genID++ });
    for (auto& y : nodeY)
        sort(y.begin(), y.end(), [](const Node& a, const Node& b) { return a.x < b.x; });
    makeTree(-1, 100001, 100001, 100000, 0);
    preorder(0), postorder(0);
    return answer;
}
