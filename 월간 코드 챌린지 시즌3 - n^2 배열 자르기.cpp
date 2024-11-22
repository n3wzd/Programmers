#include <vector>
using namespace std;
typedef long long ll;

vector<int> solution(int n, ll left, ll right) {
    vector<int> answer;
    for(ll i = left; i <= right; i++)
        answer.push_back(max(i % n, i / n) + 1);
    return answer;
}
