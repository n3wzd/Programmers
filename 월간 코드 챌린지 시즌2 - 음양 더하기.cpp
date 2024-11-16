#include <vector>
using namespace std;

int solution(vector<int> num, vector<bool> signs) {
    int answer = 0;
    for(int i = 0; i < num.size(); i++)
        answer += signs[i] ? num[i] : -num[i];
    return answer;
}
