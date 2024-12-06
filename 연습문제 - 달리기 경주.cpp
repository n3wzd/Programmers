#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<string, int> ranks;

vector<string> solution(vector<string> players, vector<string> callings) {
    for(int i = 0; i < players.size(); i++)
        ranks[players[i]] = i;
    for(auto cur : callings) {
        int r = ranks[cur]; string next = players[r - 1];
        ranks[cur] = r - 1;
        ranks[next] = r;
        players[r] = next;
        players[r - 1] = cur;
    }
    return players;
}
