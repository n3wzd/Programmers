using namespace std;
int answer = 0;

int solution(int n, int a, int b) {
    a--, b--;
    while(a != b) a /= 2, b /= 2, answer++;
    return answer;
}
