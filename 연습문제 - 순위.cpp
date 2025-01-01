#include <vector>
#include <memory.h>
using namespace std;
const int SIZE = 101;
int answer; bool visited[SIZE];
vector<int> graphW[SIZE], graphL[SIZE];

int DFS(int n, vector<int> graph[]) {
    if(visited[n])
        return 0;
    int cnt = 1; visited[n] = 1;
    for(int c : graph[n])
        cnt += DFS(c, graph);
    return cnt;
}

int solution(int n, vector<vector<int>> results) {
    for(auto edge : results) {
        graphW[edge[0]].push_back(edge[1]);
        graphL[edge[1]].push_back(edge[0]);
    }
    for(int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        int win = DFS(i, graphW) - 1;
        memset(visited, 0, sizeof(visited));
        int lose = DFS(i, graphL) - 1;
        answer += (win + lose == n - 1 ? 1 : 0);
    }
    return answer;
}
