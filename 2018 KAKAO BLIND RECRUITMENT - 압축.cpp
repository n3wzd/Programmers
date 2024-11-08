#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> dict;
string tmp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vector<int> answer;

vector<int> solution(string msg) {
    int N = msg.size(), genID = 1;
    for (; genID <= 26; genID++)
        dict[tmp.substr(genID - 1, 1)] = genID;
    for (int i = 0; i < N;) {
        int len = N - i;
        while (len) {
            string tk = msg.substr(i, len);
            if (dict[tk] > 0) {
                answer.push_back(dict[tk]);
                break;
            }
            len--;
        }
        if (len + 1 <= N)
            dict[msg.substr(i, len + 1)] = genID++;
        i += len;
    }
    return answer;
}
