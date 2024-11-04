#include <string>
#include <vector>
using namespace std;
struct Node {
    vector<Node*> c = vector<Node*>(26, nullptr);
    int cnt = 0;
};
vector<Node*> prefix = vector<Node*>(10001, nullptr);
vector<Node*> suffix = vector<Node*>(10001, nullptr);
Node* getChild(Node* a, int b) {
    if (a->c[b] == nullptr)
        a->c[b] = new Node();
    return a->c[b];
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for (int i = 1; i <= 10000; i++)
        prefix[i] = new Node(), suffix[i] = new Node();
    for (auto word : words) {
        Node* node1 = prefix[word.size()]; Node* node2 = suffix[word.size()];
        node1->cnt++; node2->cnt++;
        for (int i = 0; i < word.size(); i++) {
            node1 = getChild(node1, word[i] - 'a');
            node2 = getChild(node2, word[(word.size() - 1) - i] - 'a');
            node1->cnt++; node2->cnt++;
        }
    }
    for (auto q : queries) {
        int lo = 0, hi = q.size() - 1;
        while (q[lo] == '?') lo++;
        while (q[hi] == '?') hi--;

        string str = q.substr(lo, hi + 1);
        Node* node = lo == 0 ? prefix[q.size()] : suffix[q.size()];
        if (lo == 0)
            for (int i = 0; i < str.size(); i++)
                node = getChild(node, str[i] - 'a');
        else
            for (int i = str.size() - 1; i >= 0; i--)
                node = getChild(node, str[i] - 'a');
        answer.push_back(node->cnt);
    }
    return answer;
}
