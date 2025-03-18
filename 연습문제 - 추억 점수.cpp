#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> maps;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photos) {
    vector<int> answer;
    for(int i = 0; i < name.size(); i++)
        maps[name[i]] = yearning[i];
    for(auto photo : photos) {
        int sum = 0;
        for(auto p : photo)
            sum += maps[p];
        answer.push_back(sum);
    }
    return answer;
}
