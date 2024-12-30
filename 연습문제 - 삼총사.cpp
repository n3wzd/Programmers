#include <vector>
using namespace std;
int answer; vector<int> number;
bool selected[13];

void BT(int start, int depth) {
    if(depth == 0) {
        int sum = 0;
        for(int i = 0; i < number.size(); i++)
            if(selected[i])
            sum += number[i];
        answer += sum == 0 ? 1 : 0;
        return;
    }
    for(int i = start; i < number.size(); i++) {
        selected[i] = 1;
        BT(i + 1, depth - 1);
        selected[i] = 0;
    }
}

int solution(vector<int> numberI) {
    number = numberI; BT(0, 3);
    return answer;
}
