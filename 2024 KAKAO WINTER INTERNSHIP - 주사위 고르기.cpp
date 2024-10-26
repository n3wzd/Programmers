#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
int N, maxWin = -1;
bool selectedDice[10];
vector<int> winDeck, finalWinDeck;
vector<vector<int>> dice;

void sumDFS(vector<int>& diceIdx, vector<int>& sumList, int depth = 0, int sum = 0) {
    if (depth == N / 2) {
        sumList.push_back(sum);
        return;
    }
    for (int i = 0; i < 6; i++)
        sumDFS(diceIdx, sumList, depth + 1, sum + dice[diceIdx[depth]][i]);
}

void game() {
    vector<int> sumA, sumB, diceIdxA, diceIdxB;
    for (int s = 0; s < N; s++)
        selectedDice[s] ? diceIdxA.push_back(s) : diceIdxB.push_back(s);
    sumDFS(diceIdxA, sumA);
    sumDFS(diceIdxB, sumB);
    sort(sumB.begin(), sumB.end());

    int win = 0;
    for (int s : sumA)
        win += distance(sumB.begin(), lower_bound(sumB.begin(), sumB.end(), s));
    if (win > maxWin) {
        maxWin = win;
        winDeck = diceIdxA;
    }
}

void combination(int start = 0, int depth = 0) {
    if (depth == N / 2) {
        game();
        return;
    }
    for (int i = start; i < N; i++) {
        selectedDice[i] = 1;
        combination(i + 1, depth + 1);
        selectedDice[i] = 0;
    }
}

vector<int> solution(vector<vector<int>> diceInput) {
    dice = diceInput; N = dice.size();
    combination();
    for (int w : winDeck)
        finalWinDeck.push_back(w + 1);
    return finalWinDeck;
}
