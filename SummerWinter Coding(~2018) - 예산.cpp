#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> D, int budget) {
    int answer = 0;
    sort(D.begin(), D.end());
    for(auto d : D)
        if(budget >= d)
            budget -= d, answer++;
    return answer;
}
