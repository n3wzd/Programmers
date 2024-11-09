#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
map<string, string> note = { {"C", "1"}, {"C#", "2"}, {"D", "3"}, {"D#", "4"}, {"E", "5"}, {"F", "6"}, {"F#", "7"}, {"G", "8"}, {"G#", "9"}, {"A", "A"}, {"A#", "B"}, {"B", "C"}, {"B#", "D"} };
int ttoi(string t) { return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2)); }

string init(string m) {
    string res = "";
    for (int i = 0; i < m.size(); i++) {
        if (i < m.size() - 1) {
            string t2 = m.substr(i, 2);
            if (note[t2] != "") {
                res += note[t2]; i++;
                continue;
            }
        }
        string t1 = m.substr(i, 1);
        if (note[t1] != "")
            res += note[t1];
    }
    return res;
}

bool match(string m1, string m2) {
    int N = m1.size(), M = m2.size();
    if (N > M)
        return 0;
    for (int s = 0; s <= M - N; s++) {
        bool ok = 1;
        for (int i = 0; i < N; i++)
            ok &= m1[i] == m2[i + s];
        if (ok) return 1;
    }
    return 0;
}

string solution(string m, vector<string> musicinfos) {
    int maxSize = -1;
    string myMusic = init(m), answer = "";
    for (int i = 0; i < musicinfos.size(); i++) {
        stringstream ss(musicinfos[i]);
        string a, b, c, d; getline(ss, a, ','); getline(ss, b, ','); getline(ss, c, ','); getline(ss, d, ',');
        string sample = init(d), radioMusic = "";
        int musicTime = ttoi(b) - ttoi(a), len = sample.size(), diff = musicTime;
        while (diff >= len)
            radioMusic += sample, diff -= len;
        radioMusic += sample.substr(0, diff);
        if (maxSize < musicTime && match(myMusic, radioMusic)) {
            maxSize = musicTime;
            answer = c;
        }
    }
    return answer == "" ? "(None)" : answer;
}
