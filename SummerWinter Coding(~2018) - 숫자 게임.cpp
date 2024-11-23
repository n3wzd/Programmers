#include <algorithm>
#include <vector>
using namespace std;
    
int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end());
    for(auto a : A)
        if(a < B.back())
            B.pop_back(), answer++;
    return answer;
}
