#include <vector>
using namespace std;
int alp, cop, alpGoal, copGoal, cache[151][151];
vector<vector<int>> problems;

int DP(int a, int c) {
    if (a >= alpGoal && c >= copGoal)
        return 0;
    a = min(a, alpGoal); c = min(c, copGoal);
    if (cache[a][c] > 0)
        return cache[a][c];
    cache[a][c] = 999;
    cache[a][c] = min(cache[a][c], min(DP(a + 1, c) + 1, DP(a, c + 1) + 1));
    for (auto p : problems)
        if (a >= p[0] && c >= p[1])
            cache[a][c] = min(cache[a][c], DP(a + p[2], c + p[3]) + p[4]);
    return cache[a][c];
}

int solution(int a, int c, vector<vector<int>> pro) {
    problems = pro; alp = a, cop = c;
    for (auto p : problems)
        alpGoal = max(alpGoal, p[0]), copGoal = max(copGoal, p[1]);
    alpGoal = max(alpGoal, alp), copGoal = max(copGoal, cop);
    return DP(alp, cop);
}
