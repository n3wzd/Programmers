#include <vector>
using namespace std;
typedef long long ll;

vector<ll> solution(vector<ll> numbers) {
    vector<ll> answer; ll b = 1;
    for (auto n : numbers) {
        if (n == 0) {
            answer.push_back(1);
            continue;
        }
        int i = 0;
        while ((n & b << i) != 0) i++;
        answer.push_back((n | b << i) & ~(b << (i - 1)));
    }
    return answer;
}
