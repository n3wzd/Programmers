#include <vector>
#include <set>
using namespace std;
set<int> L;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int win = 0, zero = 0;
    for(int n : win_nums)
        L.insert(n);
    for(int n : lottos) {
        if(n == 0)
            zero++;
        else
            win += (L.find(n) != L.end()) ? 1 : 0;
    }
    return { min(7 - (zero + win), 6), min(7 - win, 6) };
}
