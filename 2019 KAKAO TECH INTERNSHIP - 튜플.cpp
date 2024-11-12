#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int lo = 2, genID;
vector<vector<int>> arr;
vector<int> answer;
set<int> items;

vector<int> solution(string s) {
    arr.push_back({ });
    for (int i = 2; i < s.size() - 1; i++) {
        if (s[i] == '}') {
            arr[genID++].push_back(stoi(s.substr(lo, i - lo)));
            arr.push_back({ });
            lo = i + 3; i += 2;
        }
        else if (s[i] == ',') {
            arr[genID].push_back(stoi(s.substr(lo, i - lo)));
            lo = i + 1;
        }
    }
    sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
        return a.size() < b.size();
        });
    for (auto subset : arr) {
        for (auto item : subset) {
            if (items.find(item) == items.end()) {
                items.insert(item);
                answer.push_back(item);
            }
        }
    }
    return answer;
}
