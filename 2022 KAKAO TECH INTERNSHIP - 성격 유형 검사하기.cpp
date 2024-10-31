#include <string>
#include <vector>
using namespace std;
int score[26];

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    for (int i = 0; i < survey.size(); i++) {
        switch (choices[i]) {
        case 1: score[survey[i][0] - 65] += 3; break;
        case 2: score[survey[i][0] - 65] += 2; break;
        case 3: score[survey[i][0] - 65] += 1; break;
        case 5: score[survey[i][1] - 65] += 1; break;
        case 6: score[survey[i][1] - 65] += 2; break;
        case 7: score[survey[i][1] - 65] += 3; break;
        }
    }
    answer += score[17] >= score[19] ? 'R' : 'T';
    answer += score[2] >= score[5] ? 'C' : 'F';
    answer += score[9] >= score[12] ? 'J' : 'M';
    answer += score[0] >= score[13] ? 'A' : 'N';
    return answer;
}
