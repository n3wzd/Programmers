#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Node { string head; int number, id; };
vector<Node> list; int genID = 0;
string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    for (auto file : files) {
        int i = 0;
        while (!(file[i] >= '0' && file[i] <= '9')) i++;
        int len = i;
        while (file[i + len] >= '0' && file[i + len] <= '9') len++;
        list.push_back({ toLower(file.substr(0, i)), stoi(file.substr(i, len)), genID++ });
    }
    stable_sort(list.begin(), list.end(), [](const Node& a, const Node& b) {
        return a.head != b.head ? a.head < b.head : a.number < b.number;
        });
    for (auto item : list)
        answer.push_back(files[item.id]);
    return answer;
}
