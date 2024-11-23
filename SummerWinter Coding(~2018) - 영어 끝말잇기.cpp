#include <string>
#include <vector>
#include <set>
using namespace std;
set<string> used;

vector<int> solution(int n, vector<string> W) {
    for(int i = 0; i < W.size(); i++) {
        if(i > 0 && (used.find(W[i]) != used.end() || W[i][0] != W[i - 1][W[i - 1].size() - 1]))
            return { i % n + 1, i / n + 1 };
        used.insert(W[i]);
    }
    return { 0, 0 };
}
