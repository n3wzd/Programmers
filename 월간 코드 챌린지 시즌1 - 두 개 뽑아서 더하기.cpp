#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer; int N = numbers.size();
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i != j)
                answer.push_back(numbers[i] + numbers[j]);
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    return answer;
}
