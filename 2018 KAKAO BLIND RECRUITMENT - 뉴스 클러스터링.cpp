#include <string>
#include <set>
#include <algorithm>
#include <cctype>
using namespace std;
multiset<string> MS;
string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

int solution(string str1, string str2) {
    for (int i = 0; i < str1.size() - 1; i++)
        if (isalpha(str1[i]) && isalpha(str1[i + 1]))
            MS.insert(toLower(str1.substr(i, 2)));
    double a = 0, b = MS.size();
    for (int i = 0; i < str2.size() - 1; i++) {
        if (isalpha(str2[i]) && isalpha(str2[i + 1])) {
            auto it = MS.find(toLower(str2.substr(i, 2)));
            if (it != MS.end()) {
                MS.erase(it);
                a++;
            }
            b++;
        }
    }
    return a == 0 && b == 0 ? 65536 : a / (b - a) * 65536;
}
