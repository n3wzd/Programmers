using namespace std;

bool solution(int x) {
    int cnt = 0, y = x;
    while(x > 0) {
        cnt += x % 10;
        x /= 10;
    }
    return y % cnt == 0;
}
