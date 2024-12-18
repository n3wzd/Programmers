#include <vector>
#include <set>
using namespace std;
int ps[2001];

int solution(vector<int> A) {
    int N = A.size(); set<int> S;
    ps[0] = A[0];
    for(int i = 1; i < N * 2; i++)
        ps[i] = ps[i - 1] + A[i % N];
    for(int i = 0; i < N; i++)
        for(int j = 1; j <= N; j++)
            S.insert(ps[i + j] - ps[i]);
    return S.size();
}
