#include <vector>
#include <queue>
using namespace std;
queue<int> q;
bool visited[200001], waited[200001];
vector<int> graph[200001];
int key[200001], door[200001], waitCnt;

bool solution(int N, vector<vector<int>> paths, vector<vector<int>> orders) {
    for (auto path : paths) {
        graph[path[0]].push_back(path[1]);
        graph[path[1]].push_back(path[0]);
    }
    for (auto order : orders) {
        key[order[1]] = order[0];
        door[order[0]] = order[1];
        if (order[1] == 0)
            return 0;
    }
    q.push(0); visited[0] = 1;
    while (!q.empty()) {
        int n = q.front(); q.pop();
        for (auto next : graph[n]) {
            if (visited[next])
                continue;
            if (!visited[key[next]]) {
                waited[next] = 1;
                waitCnt++;
            }
            else
                q.push(next);
            if (waited[door[next]]) {
                q.push(door[next]);
                waited[door[next]] = 0;
                waitCnt--;
            }
            visited[next] = 1;
        }
    }
    return waitCnt == 0;
}
