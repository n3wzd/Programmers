#include <string>
#include <vector>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int hp = health, mhp = health, t = 0;
    for (vector<int> attack : attacks) {
        int dt = attack[0] - t - 1;
        int heal = bandage[1] * dt + (bandage[2] * (dt / bandage[0]));
        hp = min(mhp, hp + heal);
        hp -= attack[1];
        if (hp <= 0)
            return -1;
        t = attack[0];
    }
    return hp;
}
