#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
vector<int> worker[4][3][3][3];
map<string, int> m;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    m["cpp"] = 0, m["java"] = 1, m["python"] = 2, m["--"] = 3;
    m["backend"] = 0, m["frontend"] = 1, m["-"] = 2;
    m["junior"] = 0, m["senior"] = 1; m["chicken"] = 0, m["pizza"] = 1;
    for (auto inf : info) {
        istringstream iss(inf);
        string a, b, c, d, e; iss >> a >> b >> c >> d >> e;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    for (int l = 0; l < 2; l++)
                        worker[i ? m[a] : 3][j ? m[b] : 2][k ? m[c] : 2][l ? m[d] : 2].push_back(stoi(e));
    }
    for (int a = 0; a < 4; a++)
        for (int b = 0; b < 3; b++)
            for (int c = 0; c < 3; c++)
                for (int d = 0; d < 3; d++)
                    sort(worker[a][b][c][d].begin(), worker[a][b][c][d].end());
    for (auto q : query) {
        istringstream iss(q);
        string a, b, c, d, e, t;
        iss >> a >> t >> b >> t >> c >> t >> d >> e;
        if (a == "-") a = "--";
        auto w = worker[m[a]][m[b]][m[c]][m[d]];
        answer.push_back(w.end() - lower_bound(w.begin(), w.end(), stoi(e)));
    }
    return answer;
}
