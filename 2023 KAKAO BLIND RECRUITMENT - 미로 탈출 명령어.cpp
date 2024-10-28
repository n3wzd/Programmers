#include <string>
#include <cmath>
using namespace std;

string solution(int n, int m, int y, int x, int goalY, int goalX, int k) {
    string answer = ""; x--, y--, goalY--, goalX--;
    int dist = abs(x - goalX) + abs(y - goalY);
    if (!(dist % 2 == k % 2 && k >= dist))
        return "impossible";
    while (k != dist) {
        if (y < n - 1)
            y++, answer += 'd';
        else if (x > 0)
            x--, answer += 'l';
        else
            x++, answer += 'r';
        k--; dist = abs(x - goalX) + abs(y - goalY);
    }
    while (k--) {
        if (y < goalY)
            y++, answer += 'd';
        else if (x > goalX)
            x--, answer += 'l';
        else if (x < goalX)
            x++, answer += 'r';
        else
            y--, answer += 'u';
    }
    return answer;
}
