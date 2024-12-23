#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
unordered_map<int, int> cnt;
vector<int> C; int idx, answer;

int solution(int k, vector<int> T) {
    for(auto t : T)
        cnt[t]++;
    sort(T.begin(), T.end());
	T.erase(unique(T.begin(), T.end()), T.end());
    for(auto t : T)
        C.push_back(cnt[t]);
    sort(C.begin(), C.end(), greater<int>());
    while(k > 0)
        k -= C[idx++], answer++;
    return answer;
}
