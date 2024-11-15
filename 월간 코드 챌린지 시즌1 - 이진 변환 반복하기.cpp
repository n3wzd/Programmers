#include <string>
#include <vector>
using namespace std;

vector<int> solution(string s) {
    int T = 0, Z = 0;
    while (s.size() > 1) {
        int cnt = 0;
        for (auto c : s) {
            if (c == '1')
                cnt++;
            else
                Z++;
        }
        s = "";
        while (cnt > 0) {
            s += cnt % 2 == 1 ? '1' : '0';
            cnt /= 2;
        }
        T++;
    }
    return { T, Z };
}
