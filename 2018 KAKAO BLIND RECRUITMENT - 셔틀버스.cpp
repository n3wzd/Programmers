#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int N, q, busTime = 540, resTime, T[1440];
int ttoi(string t) {
    return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
}
string itot(int t) {
    stringstream h, m;
    h << setw(2) << setfill('0') << to_string(t / 60);
    m << setw(2) << setfill('0') << to_string(t % 60);
    return h.str() + ":" + m.str();
}

string solution(int n, int p, int m, vector<string> timetables) {
    for (auto t : timetables)
        T[ttoi(t)]++;
    for (int t = 0; t < 1440; t++) {
        q += T[t];
        if (t == busTime && n > 0) {
            busTime += p, n--, q -= m;
            if (q < 0)
                resTime = t, q = 0;
        }
        if (q < m * n)
            resTime = t;
    }
    return itot(resTime);
}
