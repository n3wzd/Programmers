#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> users;
vector<int> emoticons;
int N, maxMember, maxIncome, sale[7];

void BT(int n = 0) {
    if (n == N) {
        int member = 0, income = 0;
        for (vector<int> user : users) {
            int preIncome = 0;
            for (int i = 0; i < N; i++)
                if (user[0] <= sale[i])
                    preIncome += emoticons[i] * (100 - sale[i]) / 100;
            preIncome >= user[1] ? member++ : income += preIncome;
        }
        if (member > maxMember || (member == maxMember && income > maxIncome))
            maxMember = member, maxIncome = income;
        return;
    }
    for (int p = 10; p <= 40; p += 10)
        sale[n] = p, BT(n + 1);
}

vector<int> solution(vector<vector<int>> usersI, vector<int> emoticonsI) {
    users = usersI, emoticons = emoticonsI; N = emoticons.size();
    BT(); return { maxMember, maxIncome };
}
