#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> table;
vector<int> parent(10001, -1);
int money[10001];

void propagate(int n, int m) {
    if(m == 0)
        return;
    if(parent[n] != -1) {
        int p = m / 10;
        money[n] += m - p;
        propagate(parent[n], p);
    }
    else
        money[n] += m;
}

vector<int> solution(vector<string> E, vector<string> R, vector<string> S, vector<int> A) {
    vector<int> answer;
    int N = E.size(); table["-"] = N;
    for (int i = 0; i < N; i++)
        table[E[i]] = i;
    for (int i = 0; i < N; i++)
        parent[i] = table[R[i]];
    for (int i = 0; i < S.size(); i++)
        propagate(table[S[i]], A[i] * 100); 
    for (int i = 0; i < N; i++)
        answer.push_back(money[i]);
    return answer;
}
