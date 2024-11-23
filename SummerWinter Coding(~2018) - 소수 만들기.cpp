#include <vector>
#include <cmath>
using namespace std;
vector<int> nums;
int N, answer;
bool selected[51];

int isPrime(int n) {
    int d = sqrt(n);
    for(int i = 2; i <= d; i++)
        if(n % i == 0)
            return 0;
    return 1;
}

void combination(int start, int depth) {
    if(depth > 2) {
        int n = 0;
        for(int i = 0; i < N; i++)
            if(selected[i])
                n += nums[i];
        answer += isPrime(n);
        return;
    }
    for(int i = start; i < N; i++){
        selected[i] = 1;
        combination(i + 1, depth + 1);
        selected[i] = 0;
    }
}

int solution(vector<int> numsI) {
    nums = numsI; N = nums.size();
    combination(0, 0);
    return answer;
}
