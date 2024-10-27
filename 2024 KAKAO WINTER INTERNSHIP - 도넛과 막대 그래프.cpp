#include <vector>
using namespace std;
int S, A, B, C, N;
vector<int> edges[1000001];
int inCnt[1000001];
int in(int n) { return inCnt[n]; }
int out(int n) { return edges[n].size(); }

vector<int> solution(vector<vector<int>> edgesInput) {
    vector<int> answer;
    for (vector<int> edge : edgesInput) {
        edges[edge[0]].push_back(edge[1]);
        N = max(N, max(edge[0], edge[1]));
        inCnt[edge[1]]++;
    }
    for (int i = 1; i <= N; i++)
        if (in(i) == 0 && out(i) >= 2)
            S = i;
    for (int next : edges[S]) {
        int first = next; bool isStart = 1;
        while (1) {
            if (out(next) == 2) {
                C++;
                break;
            }
            if (out(next) == 0) {
                B++;
                break;
            }
            if (next == first && !isStart) {
                A++;
                break;
            }
            isStart = 0;
            next = edges[next][0];
        }
    }
    return { S, A, B, C };
}
