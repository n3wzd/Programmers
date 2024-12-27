#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food) {
    string left = "", right;
    for(int i = 1; i < food.size(); i++)
        for(int j = 0; j < food[i] / 2; j++)
            left += to_string(i);
    right = left; reverse(right.begin(), right.end());
    return left + "0" + right;
}
