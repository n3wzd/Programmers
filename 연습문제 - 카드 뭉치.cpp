#include <string>
#include <vector>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int p1 = 0, p2 = 0;
    for(auto w : goal) {
        if(p1 < cards1.size() && w == cards1[p1])
            p1++;
        else if(p2 < cards2.size() && w == cards2[p2])
            p2++;
        else
            return "No";
    }
    return "Yes";
}
