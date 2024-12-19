#include <vector>
#include <cstring>
using namespace std;
bool selected[101];

int solution(vector<int> cards) {
    int N = cards.size(), answer = 0;
    for(int i = 0; i < N; i++)
        cards[i]--;
    for(int i = 0; i < N; i++) {
        memset(selected, 0, sizeof(selected));
        int score1 = 0, p = i;
        while(!selected[p]) {
            selected[p] = 1;
            p = cards[p];
            score1++;
        }
        for(int j = 0; j < N; j++) {
            int score2 = 0, p = j;
            while(!selected[p]) {
                selected[p] = 1;
                p = cards[p];
                score2++;
            }
            answer = max(answer, score1 * score2);
        }
    }
    return answer;
}
