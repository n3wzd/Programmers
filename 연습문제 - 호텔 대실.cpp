#include <string>
#include <vector>
using namespace std;
int ttoi(string t) { return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2)); }
int T[1451];

int solution(vector<vector<string>> book_time) {
    int answer = 0, sum = 0;
    for(auto book : book_time) {
        T[ttoi(book[0])]++;
        T[ttoi(book[1]) + 10]--;
    }
    for(int i = 0; i <= 1450; i++) {
        sum += T[i];
        answer = max(answer, sum);
    }
    return answer;
}
