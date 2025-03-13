using namespace std;

int solution(int n, int w, int num) {
    int answer = 0; n--, num--;
    int y = num / w, x = (y % 2 == 0 ? num % w : (w - 1) - num % w);
    while(n >= num) {
        y++, answer++;
        num = w * y + (y % 2 == 0 ? x : (w - 1) - x);
    }
    return answer;
}
