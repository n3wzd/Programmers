#include <vector>
using namespace std;

vector<int> solution(int n, int s) {
    if(s < n)
        return { -1 };
    vector<int> answer;
    int a = s / n, d = s - (n * a);
    for(int i = 0; i < n; i++)
        answer.push_back(a);
    for(int i = 0; i < d; i++)
        answer[n - 1 - i] += 1;
    return answer;
}
