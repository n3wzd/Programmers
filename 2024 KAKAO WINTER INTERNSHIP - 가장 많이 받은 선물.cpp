#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> name;
int N, gift[51][51], score[51];

int solution(vector<string> friends, vector<string> gifts) {
    N = friends.size();
    for (int i = 0; i < N; i++)
        name.insert({ friends[i], i });
    for (string str : gifts) {
        int i = 0;
        for (; i < str.size(); i++)
            if (str[i] == ' ')
                break;
        int giver = name.find(str.substr(0, i))->second;
        int taker = name.find(str.substr(i + 1, str.size()))->second;
        gift[giver][taker]++;
        score[giver]++; score[taker]--;
    }

    int maxGift = 0;
    for (int i = 0; i < N; i++) {
        int myGift = 0;
        for (int j = 0; j < N; j++)
            if (i != j && (gift[i][j] > gift[j][i] || (gift[i][j] == gift[j][i] && score[i] > score[j])))
                myGift++;
        maxGift = max(maxGift, myGift);
    }
    return maxGift;
}
