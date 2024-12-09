#include <algorithm>
#include <vector>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer, list;
    for(int s : score) {
        list.push_back(s);
        sort(list.begin(), list.end(), greater<int>());
        answer.push_back(list[min(k, (int)list.size()) - 1]);
    }
    return answer;
}
