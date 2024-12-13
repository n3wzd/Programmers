#include <vector>
using namespace std;
int roll[2][1000001];
bool top[2][10001];

int solution(vector<int> T) {
    int answer = 0, N = T.size();
    for(int i = 0; i < N; i++) {
        if(i > 0) roll[0][i] = roll[0][i - 1];
        if(!top[0][T[i]]) roll[0][i]++;
        top[0][T[i]] = 1;
    }
    for(int i = N - 1; i >= 0; i--) {
        if(i < N - 1) roll[1][i] = roll[1][i + 1];
        if(!top[1][T[i]]) roll[1][i]++;
        top[1][T[i]] = 1;
    }
    for(int i = 0; i < N - 1; i++)
        if(roll[0][i] == roll[1][i + 1])
            answer++;
    return answer;
}
