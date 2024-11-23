int warp(int n, int dist) {
    int i = 1;
    for(; i <= n; i *= 2)
        if(i == n)
            return dist;
    return warp(n - i / 2, dist + 1);
}

int solution(int n) {
    return warp(n, 1);
}
