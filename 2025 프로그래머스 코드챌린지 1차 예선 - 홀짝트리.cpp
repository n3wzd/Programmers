#include <vector>
using namespace std;
const int MAXV = 1000001;
const int MAXW = 400001;
vector<int> graph[MAXV];
int treeId[MAXV], childCnt[MAXV], genId;
int treeSize[MAXW], eoNodeCnt[MAXW], eorNodeCnt[MAXW], eo, eor;
bool eoTree[MAXW], eorTree[MAXW];
bool isEO(int v, int c) { return ((v % 2 == 1) && (c % 2 == 1)) 
    || ((v % 2 == 0) && (c % 2 == 0)); }
bool isEOR(int v, int c) { return ((v % 2 == 0) && (c % 2 == 1)) 
    || ((v % 2 == 1) && (c % 2 == 0)); }

void DFS(int v, int id) {
    if(treeId[v] > 0)
        return;
    treeId[v] = id;
    childCnt[v] = graph[v].size() - 1;
    eoNodeCnt[id] += isEO(v, childCnt[v]) ? 1 : 0;
    eorNodeCnt[id] += isEOR(v, childCnt[v]) ? 1 : 0;
    treeSize[id]++;
    for(int next : graph[v])
        DFS(next, id);
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    for(auto edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    for(int v : nodes)
        DFS(v, ++genId);
    for(int v : nodes) {
        int id = treeId[v];
        if(graph[v].size() == 0) {
            eoTree[id] |= (v % 2 == 0);
            eorTree[id] |= (v % 2 == 1);
        }
        else {
            int eot = eoNodeCnt[id] + (isEO(v, childCnt[v]) ? -1 : 0);
            int eort = eorNodeCnt[id] + (isEOR(v, childCnt[v]) ? -1 : 0);
            eot += isEO(v, childCnt[v] + 1) ? 1 : 0;
            eort += isEOR(v, childCnt[v] + 1) ? 1 : 0;
            eoTree[id] |= (eot == treeSize[id]);
            eorTree[id] |= (eort == treeSize[id]);
        }
    }
    for(int i = 0; i < MAXW; i++) {
        if(eoTree[i]) eo++;
        if(eorTree[i]) eor++;
    }
    return { eo, eor };
}
