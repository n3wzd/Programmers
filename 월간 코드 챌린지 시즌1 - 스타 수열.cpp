#include <vector>
#include <set>
using namespace std;
set<int> S[500001];

int solution(vector<int> A) {
    int N = A.size(), answer = 0;
    for(int i = 0; i < N; i++) {
        if(i > 0 && A[i - 1] != A[i] && S[A[i]].find(i - 1) == S[A[i]].end())
            S[A[i]].insert(i - 1);
        else if(i < N - 1 && A[i + 1] != A[i])
            S[A[i]].insert(i + 1);
    }
    for(int a = 0; a < N; a++)
        answer = max(answer, (int)S[a].size());  
    return answer * 2;
}
