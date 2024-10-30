#include <vector>
using namespace std;
vector<int> peach, ryan(11, 0), answer, failAnswer = { -1 };
int highscore = -1;

void BT(int level, int life) {
    if (level == 10) {
        ryan[level] = life;
        int myScore = 0, enemyScore = 0;
        for (int i = 0; i <= 10; i++)
            if (peach[i] != 0 || ryan[i] != 0)
                peach[i] >= ryan[i] ? enemyScore += 10 - i : myScore += 10 - i;
        if (myScore > enemyScore) {
            bool ok = (myScore - enemyScore) > highscore;
            if ((myScore - enemyScore) == highscore) {
                for (int i = 10; i >= 0; i--) {
                    if (ryan[i] > answer[i])
                        ok = 1;
                    if (ryan[i] != answer[i])
                        break;
                }
            }
            if (ok) {
                highscore = max(highscore, myScore - enemyScore);
                answer = ryan;
            }
        }
        ryan[level] = 0;
        return;
    }
    if (life >= peach[level] + 1) {
        ryan[level] = peach[level] + 1;
        BT(level + 1, life - (peach[level] + 1));
    }
    if (life >= peach[level]) {
        ryan[level] = peach[level];
        BT(level + 1, life - peach[level]);
    }
    ryan[level] = 0;
    BT(level + 1, life);
}

vector<int> solution(int n, vector<int> info) {
    peach = info;
    BT(0, n);
    return highscore == -1 ? failAnswer : answer;
}
