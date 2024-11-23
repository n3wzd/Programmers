#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> cookie) {
    int answer = 0, N = cookie.size();
    for(int s = 0; s < N; s++) {
        deque<int> L, R;
        int sumL = 0, sumR = 0, i = s;
        while(i < N) {
            while(i < N && sumL >= sumR) {
                if(sumL == sumR)
                    answer = max(answer, sumL);
                R.push_back(cookie[i]);
                sumR += cookie[i]; i++;
            }
            while(sumL < sumR) {
                L.push_back(R.front()); R.pop_front();
                sumL += L.back(), sumR -= L.back();
            }
            if(sumL == sumR)
                answer = max(answer, sumL);
        }
    }
    return answer;
}
