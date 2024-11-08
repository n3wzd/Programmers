#include <string>
#include <vector>
using namespace std;
struct Node {
    vector<Node*> c = vector<Node*>(26, nullptr);
    int cnt = 0;
    bool end = 0;
};
Node* root = new Node();
int answer = 0;

Node* getChild(Node* a, int b) {
    if (a->c[b] == nullptr)
        a->c[b] = new Node();
    return a->c[b];
}

void DFS(Node* n, int depth) {
    if (n->cnt == 1) {
        answer += depth;
        return;
    }
    if (n->end)
        answer += depth;
    for (auto child : n->c)
        if (child != nullptr)
            DFS(child, depth + 1);
}

int solution(vector<string> words) {
    for (auto word : words) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            node = getChild(node, word[i] - 'a');
            node->cnt++;
        }
        node->end = 1;
    }
    DFS(root, 0);
    return answer;
}
