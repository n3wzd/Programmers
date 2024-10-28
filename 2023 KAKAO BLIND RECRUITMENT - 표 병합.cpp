#include <string>
#include <sstream>
#include <vector>
using namespace std;
int N, M, parent[2501];
string value[2501];
int getN(int x, int y) { return (y - 1) * 50 + x - 1; }

int find(int n) {
    int p = n;
    while (parent[p] >= 0) p = parent[p];
    if (parent[n] >= 0) parent[n] = p;
    return p;
}

void merge(int a, int b) {
    int p1 = find(a);
    int p2 = find(b);
    if (p1 == p2) return;
    parent[p2] = p1;
    if (value[p1] == "")
        value[p1] = value[p2];
}

void unmerge(int n) {
    int p = find(n);
    string v = value[p];
    vector<int> q;
    for (int i = 0; i <= 2500; i++)
        if (find(i) == p)
            q.push_back(i);
    for (int i : q)
        parent[i] = -1, value[i] = "";
    value[n] = v;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    for (int i = 0; i <= 2500; i++)
        parent[i] = -1, value[i] = "";
    for (string cmd : commands) {
        istringstream iss(cmd);
        string word;
        vector<string> words;
        while (iss >> word)
            words.push_back(word);

        if (words[0] == "UPDATE" && words.size() == 4)
            value[find(getN(stoi(words[2]), stoi(words[1])))] = words[3];
        if (words[0] == "UPDATE" && words.size() == 3)
            for (int n = 0; n <= 2500; n++)
                if (value[n] == words[1])
                    value[n] = words[2];
        if (words[0] == "MERGE")
            merge(getN(stoi(words[2]), stoi(words[1])), getN(stoi(words[4]), stoi(words[3])));
        if (words[0] == "UNMERGE")
            unmerge(getN(stoi(words[2]), stoi(words[1])));
        if (words[0] == "PRINT") {
            string v = value[find(getN(stoi(words[2]), stoi(words[1])))];
            answer.push_back(v == "" ? "EMPTY" : v);
        }
    }
    return answer;
}
