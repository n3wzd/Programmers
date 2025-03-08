#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> types;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    for(auto clothe : clothes) 
        types[clothe[1]]++;
    for(auto entry: types)
        answer *= entry.second + 1; 
    return answer - 1;
}
