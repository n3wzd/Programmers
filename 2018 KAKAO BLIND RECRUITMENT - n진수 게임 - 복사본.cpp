#include <string>
#include <vector>
using namespace std;
string list[20] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int solution(string s) {
    string answer = ""; s += "     ";
    for (int i = 0; i < s.size(); i++) {
        for (int d = 0; d < 20; d++) {
            if (s.substr(i, list[d].size()) == list[d]) {
                answer += list[d % 10];
                i += list[d].size() - 1;
                break;
            }
        }
    }
    return stoi(answer);
}
