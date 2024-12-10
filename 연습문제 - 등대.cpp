#include <vector>
using namespace std;
const int SIZE = 100001;
vector<int> graph[SIZE];
int cache[SIZE][2];

int DFS(int v, int flag, int p = -1) {
    if(cache[v][flag] > 0)
        return cache[v][flag];
    cache[v][flag] = flag ? 1 : 0;
    for(int n : graph[v])
        if(n != p)
            cache[v][flag] += min(DFS(n, 1, v), flag ? DFS(n, 0, v) : SIZE);
    return cache[v][flag];
}

int solution(int n, vector<vector<int>> edges) {
    for(auto edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    return min(DFS(1, 0), DFS(1, 1));
}
