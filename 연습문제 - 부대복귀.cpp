#include <vector>
#include <queue>
#define SIZE 100001
using namespace std;
vector<int> graph[SIZE];
int dist[SIZE];

void BFS(int S) {
    queue<int> q;
    q.push(S); dist[S] = 1;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(int next : graph[v]) {
            if(dist[next] == 0) {
                dist[next] = dist[v] + 1;
                q.push(next);
            }
        } 
    }
}

vector<int> solution(int n, vector<vector<int>> R, vector<int> S, int D) {
    vector<int> answer;
    for(auto r : R) {
        graph[r[0]].push_back(r[1]);
        graph[r[1]].push_back(r[0]);
    }
    BFS(D);
    for(int s : S)
        answer.push_back(dist[s] != 0 ? dist[s] - 1 : -1);
    return answer;
}
