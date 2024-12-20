#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> target, cnt;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0, N = want.size();
    for(int i = 0; i < N; i++)
        target[want[i]] = number[i];
    for(int i = 0; i < discount.size(); i++) {
        cnt[discount[i]]++;
        if(i >= 10)
            cnt[discount[i - 10]]--;
        bool ok = 1;
        for(int j = 0; j < N; j++)
            ok &= target[want[j]] == cnt[want[j]];
        if(ok)
            answer++;
    }
    return answer;
}
