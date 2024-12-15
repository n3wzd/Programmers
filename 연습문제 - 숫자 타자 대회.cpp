#include <string>
#include <vector>
using namespace std;
vector<int> N;
int cache[100001][10][10], C[10][10] = {
    { 1, 7, 6, 7, 5, 4, 5, 3, 2, 3 },
    { 7, 1, 2, 4, 2, 3, 5, 4, 5, 6 },
    { 6, 2, 1, 2, 3, 2, 3, 5, 4, 5 },
    { 7, 4, 2, 1, 5, 3, 2, 6, 5, 4 },
    { 5, 2, 3, 5, 1, 2, 4, 2, 3, 5 },
    { 4, 3, 2, 3, 2, 1, 2, 3, 2, 3 },
    { 5, 5, 3, 2, 4, 2, 1, 5, 3, 2 },
    { 3, 4, 5, 6, 2, 3, 5, 1, 2, 4 },
    { 2, 5, 4, 5, 3, 2, 3, 2, 1, 2 },
    { 3, 6, 5, 4, 5, 3, 2, 4, 2, 1 },
};

int DP(int n, int l, int r) {
    if(n >= N.size())
        return 0;
    if(cache[n][l][r] > 0)
        return cache[n][l][r];
    cache[n][l][r] = 1e9;
    if(r != N[n])
        cache[n][l][r] = min(cache[n][l][r], DP(n + 1, N[n], r) + C[l][N[n]]);
    if(l != N[n])
        cache[n][l][r] = min(cache[n][l][r], DP(n + 1, l, N[n]) + C[r][N[n]]);
    return cache[n][l][r];
}

int solution(string numbers) {
    for(auto c : numbers)
        N.push_back(c - '0');
    return DP(0, 4, 6);
}
