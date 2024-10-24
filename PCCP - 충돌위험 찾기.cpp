#include <string>
#include <vector>
using namespace std;
struct Robot { int x, y, goalIdx; };
struct Point { int x, y; };
int board[101][101], C;

void addCollide() {
    for (int y = 1; y <= 100; y++)
        for (int x = 1; x <= 100; x++)
            C += board[y][x] > 1 ? 1 : 0;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int M = routes[0].size(), N = routes.size();
    vector<Robot> robots;
    for (vector<int> route : routes) {
        int x = points[route[0] - 1][1], y = points[route[0] - 1][0];
        robots.push_back({ x, y, 1 });
        board[y][x] += 1;
    }
    addCollide();

    while (1) {
        bool isEnd = 1;
        for (int i = 0; i < N; i++) {
            Robot& robot = robots[i];
            if (robot.goalIdx > M)
                continue;
            if (robot.goalIdx == M) {
                board[robot.y][robot.x] -= 1;
                robot.goalIdx++;
                continue;
            }
            isEnd = 0;

            board[robot.y][robot.x] -= 1;
            int gx = points[routes[i][robot.goalIdx] - 1][1], gy = points[routes[i][robot.goalIdx] - 1][0];
            if (robot.y < gy)
                robot.y++;
            else if (robot.y > gy)
                robot.y--;
            else {
                if (robot.x < gx)
                    robot.x++;
                else if (robot.x > gx)
                    robot.x--;
            }
            board[robot.y][robot.x] += 1;
            if (robot.x == gx && robot.y == gy)
                robot.goalIdx++;
        }
        addCollide();
        if (isEnd)
            break;
    }
    return C;
}
