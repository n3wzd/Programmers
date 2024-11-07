#include <string>
#include <vector>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < arr1.size(); i++) {
        int y = arr1[i] | arr2[i]; string s = "";
        for (int x = n - 1; x >= 0; x--)
            s += y & (1 << x) ? '#' : ' ';
        answer.push_back(s);
    }
    return answer;
}
