#include <iostream>
#include <vector>
using namespace std;
vector<int> childs[300001], sales;
int cache[300001][2];

int DP(int n, int must) {
    if (cache[n][must] != -1)
        return cache[n][must];
    if (childs[n].size() == 0)
        return must ? sales[n] : 0;
    cache[n][must] = sales[n];
    for (int c : childs[n])
        cache[n][must] += DP(c, 0);
    if (!must) {
        for (int c1 : childs[n]) {
            int sum = DP(c1, 1);
            for (int c2 : childs[n])
                if (c1 != c2)
                    sum += DP(c2, 0);
            cache[n][must] = min(cache[n][must], sum);
        }
    }
    return cache[n][must];
}

int solution(vector<int> sales1, vector<vector<int>> links) {
    sales = sales1;
    for (int i = 0; i < sales.size(); i++)
        cache[i][0] = cache[i][1] = -1;
    for (auto edg : links)
        childs[edg[0] - 1].push_back(edg[1] - 1);
    return DP(0, 0);
}
