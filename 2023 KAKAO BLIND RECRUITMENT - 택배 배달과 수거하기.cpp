#include <vector>
using namespace std;
int success, last;
long long cnt = 0;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    for (int i = 0; i < n; i++)
        deliveries[i] == 0 ? success++ : last = max(last, i);
    for (int i = 0; i < n; i++)
        pickups[i] == 0 ? success++ : last = max(last, i);
    while (success != n * 2) {
        int c = cap, d = cap, i = last, j = last;
        while (i >= 0) {
            if (deliveries[i] > 0) {
                if (c >= deliveries[i]) {
                    c -= deliveries[i];
                    deliveries[i] = 0;
                    success++;
                }
                else {
                    deliveries[i] -= c;
                    c = 0;
                    break;
                }
            }
            i--;
        }
        while (j >= 0) {
            if (pickups[j] > 0) {
                if (d >= pickups[j]) {
                    d -= pickups[j];
                    pickups[j] = 0;
                    success++;
                }
                else {
                    pickups[j] -= d;
                    d = 0;
                    break;
                }
            }
            j--;
        }
        cnt += (last + 1) * 2;
        last = max(i, j);
    }
    return cnt;
}
