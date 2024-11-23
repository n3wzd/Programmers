#include <string>
using namespace std;
int road[11][11][2];

int solution(string dirs) {
    int answer = 0, x = 5, y = 5;
    for(auto d : dirs) {
        if(d == 'L' && x > 0) road[y][--x][0] = 1;
        if(d == 'R' && x < 10) road[y][x++][0] = 1;
        if(d == 'U' && y > 0) road[--y][x][1] = 1;
        if(d == 'D' && y < 10) road[y++][x][1] = 1;
    }
    for(int r = 0; r < 11; r++)
        for(int c = 0; c < 11; c++)
            answer += road[r][c][0] + road[r][c][1];
    return answer;
}
