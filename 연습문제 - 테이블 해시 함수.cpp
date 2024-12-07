#include <vector>
#include <algorithm>
using namespace std;

int S(vector<int> d, int n) {
    int sum = 0;
    for(int i = 0; i < d.size(); i++)
        sum += d[i] % n;
    return sum;
}

int solution(vector<vector<int>> data, int col, int lo, int hi) {
    col--; lo--; hi--;
    sort(data.begin(), data.end(), [col](auto a, auto b) {
        return a[col] != b[col] ? a[col] < b[col] : a[0] > b[0];
    });
    int answer = S(data[lo], lo + 1);
    for(int i = lo + 1; i <= hi; i++)
        answer ^= S(data[i], i + 1);
    return answer;
}
