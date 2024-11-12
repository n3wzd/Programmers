#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
struct Node { char op; ll n; };
vector<Node> list;

void init(string expr) {
    int lo = 0, hi = 0;
    for (; hi < expr.size(); hi++) {
        if (!(expr[hi] >= '0' && expr[hi] <= '9')) {
            list.push_back({ ' ', stoi(expr.substr(lo, hi - lo)) });
            list.push_back({ expr[hi], 0 });
            lo = hi + 1;
        }
    }
    list.push_back({ ' ', stoi(expr.substr(lo, hi - lo)) });
}

ll cal(vector<int> order) {
    deque<Node> q;
    for (auto n : list)
        q.push_back(n);
    for (auto target : order) {
        int size = q.size();
        while (size > 1) {
            auto a = q.front(); q.pop_front();
            auto op = q.front(); q.pop_front();
            auto b = q.front(); q.pop_front();
            if (op.op == target) {
                if (op.op == '+')
                    q.push_front({ ' ', a.n + b.n });
                if (op.op == '-')
                    q.push_front({ ' ', a.n - b.n });
                if (op.op == '*')
                    q.push_front({ ' ', a.n * b.n });
            }
            else {
                q.push_back(a);
                q.push_back(op);
                q.push_front(b);
            }
            size -= 2;
        }
        q.push_back(q.front()); q.pop_front();
    }
    return abs(q.front().n);
}

ll solution(string expr) {
    init(expr);
    return max(cal({ '+', '-', '*' }), max(cal({ '+', '*', '-' }),
        max(cal({ '-', '+', '*' }), max(cal({ '-', '*', '+' }),
            max(cal({ '*', '+', '-' }), cal({ '*', '-', '+' }))))));
}
