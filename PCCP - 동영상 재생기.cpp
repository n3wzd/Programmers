#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int strToInt(string time) {
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

string intToStr(int t) {
    stringstream m, s;
    m << setw(2) << setfill('0') << to_string(t / 60);
    s << setw(2) << setfill('0') << to_string(t % 60);
    return "" + m.str() + ":" + s.str();
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int len = strToInt(video_len), p = strToInt(pos);
    int start = strToInt(op_start), end = strToInt(op_end);

    if (p >= start && p <= end)
        p = end;
    for (string cmd : commands) {
        if (cmd == "next")
            p = min(p + 10, len);
        if (cmd == "prev")
            p = max(p - 10, 0);
        if (p >= start && p <= end)
            p = end;
    }
    return intToStr(p);
}
