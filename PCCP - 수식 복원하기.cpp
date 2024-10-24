#include <string>
#include <vector>
#include <regex>
using namespace std;
struct Expr { int a, b, c; bool add; };
vector<Expr> X, N;
vector<string> finalX;
bool base[10];

void parshing(string str) {
    int s = 0; Expr expr;
    regex reg("(\\d+|[+\\-*/=])");  smatch match;
    sregex_iterator begin(str.begin(), str.end(), reg), end;
    for (sregex_iterator i = begin; i != end; i++, s++) {
        if (s == 0)
            expr.a = stoi(i->str());
        if (s == 1)
            expr.add = i->str() == "+";
        if (s == 2)
            expr.b = stoi(i->str());
        if (s == 4)
            expr.c = stoi(i->str());
    }
    str[str.size() - 1] == 'X' ? (X.push_back(expr), finalX.push_back(str)) : N.push_back(expr);
}

vector<string> solution(vector<string> expressions) {
    int lo = 1, hi = 9;
    for (string str : expressions)
        parshing(str);

    for (Expr expr : X)
        lo = max(lo, max(expr.a / 10, max(expr.a % 10, max(expr.b / 10, expr.b % 10))));
    for (Expr expr : N)
        lo = max(lo, max(expr.a / 10, max(expr.a % 10, max(expr.b / 10, max(expr.b % 10, max(expr.c / 100, max((expr.c % 100) / 10, expr.c % 10)))))));
    lo++;

    for (int bs = lo; bs <= hi; bs++) {
        base[bs] = 1;
        for (Expr expr : N) {
            int A = ((expr.a / 10) * bs) + expr.a % 10;
            int B = ((expr.b / 10) * bs) + expr.b % 10;
            int C = ((expr.c / 100) * bs * bs) + (((expr.c % 100) / 10) * bs) + expr.c % 10;
            base[bs] &= expr.add ? A + B == C : A - B == C;
        }
    }

    for (int i = 0; i < X.size(); i++) {
        Expr expr = X[i];
        vector<int> answers; bool isSame = 0; int answerBase = 0;
        for (int bs = lo; bs <= hi; bs++) {
            if (base[bs]) {
                int A = ((expr.a / 10) * bs) + expr.a % 10;
                int B = ((expr.b / 10) * bs) + expr.b % 10;
                int C = expr.add ? A + B : A - B;
                int subC[3] = { C / (bs * bs), (C % (bs * bs)) / bs, C % bs };
                answers.push_back(subC[0] * 100 + subC[1] * 10 + subC[2]);
            }
        }
        if (answers.size() > 0) {
            answerBase = answers[0]; isSame = 1;
            for (int answer : answers)
                isSame &= answerBase == answer;
        }
        if (isSame)
            finalX[i] = finalX[i].substr(0, finalX[i].size() - 1) + to_string(answerBase);
        else
            finalX[i][finalX[i].size() - 1] = '?';
    }
    return finalX;
}
