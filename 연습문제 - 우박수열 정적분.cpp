#include <vector>
using namespace std;
int N; double W[201], A[201];

void init(int n) {
    for(N = 0; n != 1 && N <= 200; N++) {
        W[N] = n;
        if(N > 0)
            A[N] = A[N - 1] + (W[N] + W[N - 1]) / 2;
        n = n % 2 == 0 ? n / 2 : n * 3 + 1;
    }
    W[N] = 1, A[N] = A[N - 1] + (W[N] + W[N - 1]) / 2; N++;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer; init(k);
    for(auto range : ranges) {
        int lo = range[0], hi = N + range[1] - 1;
        answer.push_back(lo <= hi ? A[hi] - A[lo] : -1);
    }
    return answer;
}
