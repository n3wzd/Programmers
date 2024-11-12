#include <string>
#include <vector>
#include <cmath>
using namespace std;
struct Point { int x, y; };
int distance(Point a, Point b) { return abs(a.x - b.x) + abs(a.y - b.y); }
Point P[10] = { {1, 3} };

string solution(vector<int> numbers, string hand) {
    string answer = "";
    Point left = { 0, 3 }, right = { 2, 3 };
    for (int i = 0; i < 10; i++)
        P[i + 1] = { i % 3, i / 3 };
    for (auto n : numbers) {
        bool isLeft;
        int distL = distance(left, P[n]), distR = distance(right, P[n]);
        if (n == 1 || n == 4 || n == 7)
            isLeft = 1;
        else if (n == 3 || n == 6 || n == 9)
            isLeft = 0;
        else if (distL == distR)
            isLeft = hand == "left";
        else
            isLeft = distL < distR;
        if (isLeft) {
            left = P[n];
            answer += "L";
        }
        else {
            right = P[n];
            answer += "R";
        }
    }
    return answer;
}
