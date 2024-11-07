#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, T;
queue<string> cache;
bool compare(string a, string b) {
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    return a == b;
}

int find(string s) {
    bool hit = 0; int size = cache.size();
    while (size--) {
        string data = cache.front(); cache.pop();
        if (compare(data, s))
            hit = 1;
        else
            cache.push(data);
    }
    cache.push(s);
    if (hit)
        return 1;
    else if (cache.size() > N)
        cache.pop();
    return 5;
}

int solution(int cacheSize, vector<string> cities) {
    N = cacheSize;
    for (auto d : cities)
        T += find(d);
    return T;
}
