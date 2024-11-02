#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
map<string, int> cnt;
int maxCntByItem[11];
bool selected[11];

void combination(string str, int k, int d, int start) {
    if (k == d) {
        string menu = "";
        for (int i = 0; i < str.size(); i++)
            if (selected[i])
                menu += str[i];
        auto data = cnt.find(menu);
        if (data != cnt.end()) {
            data->second++;
            maxCntByItem[k] = max(maxCntByItem[k], data->second);
        }
        else
            cnt.insert({ menu, 1 });
    }
    for (int i = start; i < str.size(); i++) {
        selected[i] = 1;
        combination(str, k, d + 1, i + 1);
        selected[i] = 0;
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (auto& order : orders)
        sort(order.begin(), order.end());
    for (auto order : orders)
        for (auto c : course)
            if (c <= order.size())
                combination(order, c, 0, 0);
    for (const auto& menu : cnt)
        if (maxCntByItem[menu.first.size()] == menu.second)
            answer.push_back(menu.first);
    sort(answer.begin(), answer.end());
    return answer;
}
