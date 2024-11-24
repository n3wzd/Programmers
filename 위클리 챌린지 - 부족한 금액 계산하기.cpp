using namespace std;
typedef long long ll;

ll solution(int price, int money, int count) {
    ll answer = ((ll)count * (count + 1)) / 2 * price - money;
    return answer > 0 ? answer : 0;
}
