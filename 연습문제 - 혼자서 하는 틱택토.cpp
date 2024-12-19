#include <string>
#include <vector>
using namespace std;

bool hasBingo(vector<string> B, int ex, int ey) {
    bool ok = 0; B[ey][ex] = '.';
    for(int y = 0; y < 3; y++)
        ok |= (B[y][0] == B[y][1] && B[y][0] == B[y][2] && B[y][0] != '.');
    for(int x = 0; x < 3; x++)
        ok |= (B[0][x] == B[1][x] && B[0][x] == B[2][x] && B[0][x] != '.');
    ok |= (B[0][0] == B[1][1] && B[0][0] == B[2][2] && B[0][0] != '.');
    ok |= (B[0][2] == B[1][1] && B[0][2] == B[2][0] && B[0][2] != '.');
    return ok;
}

int solution(vector<string> B) {
    int a = 0, b = 0;
    for(int y = 0; y < 3; y++)
        for(int x = 0; x < 3; x++)
            a += (B[y][x] == 'O' ? 1 : 0), b += (B[y][x] == 'X' ? 1 : 0);
    bool ok = 0;
    for(int y = 0; y < 3; y++)
        for(int x = 0; x < 3; x++)
            if((a == b + 1 && B[y][x] == 'O') || (a == b && B[y][x] == 'X'))
                ok |= !hasBingo(B, x, y);
    return ok || (a == 0 && b == 0);
}
