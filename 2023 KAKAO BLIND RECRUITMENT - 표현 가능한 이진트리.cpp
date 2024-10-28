#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
bool tree[65]; int pass;

bool DFS(int n, int level) {
    if (level <= 1)
        return tree[n - 1];
    bool hasLive = 0;
    hasLive |= DFS(n + level / 2, level / 2);
    hasLive |= DFS(n - level / 2, level / 2);
    if (hasLive && !tree[n - 1])
        pass = 0;
    return tree[n - 1];
}

int isTree(long long n) {
    memset(tree, 0, sizeof(tree));
    int len = 0, root = 1; pass = 1;
    while (n > 0) tree[len++] = n % 2, n /= 2;
    while (root < len) root *= 2;
    root /= 2;
    DFS(root, root);
    return pass;
}

vector<int> solution(vector<ll> numbers) {
    vector<int> answer;
    for (ll n : numbers)
        answer.push_back(isTree(n));
    return answer;
}
