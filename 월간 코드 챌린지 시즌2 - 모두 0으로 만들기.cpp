#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
ll answer;
vector<int> graph[300001];
vector<ll> w;

ll DFS(int n, int prev) {
    for(int c : graph[n])
        if(c != prev)
            w[n] += DFS(c, n);
    answer += abs(w[n]);
    return w[n];
}

ll solution(vector<int> a, vector<vector<int>> edges) {
    for(auto b : a)
        w.push_back(b);
    for(auto edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    return DFS(0, -1) == 0 ? answer : -1;
}
