using namespace std;
int getTime(int h, int m, int s) { return h * 3600 + m * 60 + s; }
bool isLeft(int a, int b) { int d = b - a; return (d > 0 && d <= 21600) || d < -21600; }

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int cnt = 0, lo = getTime(h1, m1, s1), hi = getTime(h2, m2, s2), diff = hi - lo;
    int s = s1 * 720, m = m1 * 720 + s1 * 12, h = (h1 % 12) * 3600 + m1 * 60 + s1;
    if (s == m) cnt++;
    if (s == h) cnt++;
    if (m == h) cnt--;
    while (diff--) {
        h = (h + 1) % 43200;
        m = (m + 12) % 43200;
        s = (s + 720) % 43200;
        if ((isLeft((s + 42480) % 43200, (m + 43188) % 43200) && !isLeft(s, m)) || s == m)
            cnt++;
        if ((isLeft((s + 42480) % 43200, (h + 43199) % 43200) && !isLeft(s, h)) || s == h)
            cnt++;
        if (s == m && s == h && m == h)
            cnt--;
    }
    return cnt;
}
