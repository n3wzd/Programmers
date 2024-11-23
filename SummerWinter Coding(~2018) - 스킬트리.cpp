#include <string>
#include <vector>
using namespace std;
bool tech[26];

int solution(string user_skill, vector<string> skill_trees) {
    int answer = 0;
    for(auto skill : user_skill)
        tech[skill - 'A'] = 1;
    for(auto skill_tree : skill_trees) {
        string ext = "";
        for(auto skill : skill_tree)
            if(tech[skill - 'A'])
                ext += skill;
        bool ok = 1;
        for(int i = 0; i < ext.size(); i++)
            ok &= ext[i] == user_skill[i];
        answer += ok ? 1 : 0;
    }
    return answer;
}
