#include <string>
#include <sstream>
#include <vector>
using namespace std;
int in[10001], sum[10001];
int timeToN(string t) { return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2)) + 1; }

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int lastTime = timeToN("23:59");
    for (string cmd : records) {
        istringstream iss(cmd);
        vector<string> words(3);
        for (auto& word : words) iss >> word;
        int id = stoi(words[1]);
        if (words[2] == "IN")
            in[id] = timeToN(words[0]);
        else
            sum[id] += timeToN(words[0]) - in[id], in[id] = 0;
    }
    for (int i = 0; i < 10000; i++)
        if (in[i] != 0)
            sum[i] += lastTime - in[i];
    for (int i = 0; i < 10000; i++) {
        if (sum[i] == 0) continue;
        int overTime = 0;
        if (sum[i] > fees[0]) {
            overTime = (sum[i] - fees[0]) / fees[2];
            if ((sum[i] - fees[0]) % fees[2] != 0)
                overTime++;
        }
        answer.push_back(fees[1] + overTime * fees[3]);
    }
    return answer;
}
