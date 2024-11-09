#include <string>
#include <vector>
#include <algorithm>
using namespace std;
char C[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
string convert(int num, int n) {
    string s = "";
    while (num > 0)
        s += C[num % n], num /= n;
    reverse(s.begin(), s.end());
    return s;
}

string solution(int n, int t, int m, int p) {
    string answer = "", list = "0";
    int idx = 0; p--;
    while (idx++ <= t * m)
        list += convert(idx, n);
    while (t--)
        answer += list[p], p += m;
    return answer;
}
