#include <vector>
using namespace std;
int N, turn, coin, life, items, price[1001];
bool hasFirstCard[1001], hasCard[1001];
vector<int> cards;

void shop(int card) {
    if (price[card] == 1 && coin > 0)
        coin--, life++;
    if (price[card] == 2)
        items++;
}

int solution(int coinInput, vector<int> cardsInput) {
    coin = coinInput; cards = cardsInput; N = cards.size();
    for (int i = 0; i < N / 3; i++) {
        if (hasFirstCard[N + 1 - cards[i]])
            life++;
        hasFirstCard[cards[i]] = 1;
    }
    for (int i = N / 3; i < N; i++) {
        if (hasFirstCard[N + 1 - cards[i]])
            price[cards[i]] = 1;
        if (hasCard[N + 1 - cards[i]])
            price[cards[i]] = 2;
        hasCard[cards[i]] = 1;
    }
    for (; turn < N / 3; turn++) {
        int idx = N / 3 + turn * 2;
        shop(cards[idx]), shop(cards[idx + 1]);
        if (life < turn + 1) {
            if (items > 0 && coin > 1)
                items--, coin -= 2, life++;
            else
                break;
        }
    }
    return turn + 1;
}
