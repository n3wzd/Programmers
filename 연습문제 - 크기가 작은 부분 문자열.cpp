#include <string>
#include <vector>
using namespace std;

int solution(string t, string p) {
    int answer = 0, N = t.size(), M = p.size();
    for(int i = 0; i <= N - M; i++)
        if(t.substr(i, M) <= p)
            answer++;
    return answer;
}
