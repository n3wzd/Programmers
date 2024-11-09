#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool digit(char c) { return c >= '0' && c <= '9'; }
vector<int> list;

int solution(string s) {
    int answer = 0;
    for (int i = 0; i < s.size(); i += 2) {
        int n; bool d1 = digit(s[i]), d2 = digit(s[i + 1]);
        d1&& d2 ? n = 10, i++ : n = stoi(s.substr(i, 1));
        if (s[i + 1] == 'D')
            n *= n;
        if (s[i + 1] == 'T')
            n *= n * n;
        if (i + 2 < s.size() && s[i + 2] == '*') {
            if (list.size() > 0)
                list[list.size() - 1] *= 2;
            n *= 2, i++;
        }
        if (i + 2 < s.size() && s[i + 2] == '#')
            n *= -1, i++;
        list.push_back(n);
    }
    for (int i = 0; i < list.size(); i++)
        answer += list[i];
    return answer;
}
