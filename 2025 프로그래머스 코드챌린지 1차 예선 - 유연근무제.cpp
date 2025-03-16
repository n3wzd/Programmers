#include <vector>
using namespace std;
int ttoi(int t) { return t % 100 + (t / 100) * 60; }

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for(int i = 0; i < timelogs.size(); i++) {
        bool ok = 1;
        for(int j = 0; j < 7; j++)
            if(!((startday + j) % 7 == 6 || (startday + j) % 7 == 0))
                ok &= ttoi(schedules[i]) + 10 >= ttoi(timelogs[i][j]);
        answer += ok ? 1 : 0;
    }
    return answer;
}
