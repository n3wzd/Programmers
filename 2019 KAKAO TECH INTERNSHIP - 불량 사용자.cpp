#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
set<string> S;
vector<int> caught[8];
int selected[8], N, M;

bool cmp(string user, string ban) {
    if (user.size() != ban.size())
        return 0;
    for (int i = 0; i < user.size(); i++)
        if (ban[i] != '*' && user[i] != ban[i])
            return 0;
    return 1;
}

void BT(int depth) {
    if (depth == N) {
        int item[8];
        for (int i = 0; i < N; i++)
            item[i] = selected[i];
        sort(item, item + N);

        string res = "";
        for (int i = 0; i < N; i++)
            res += to_string(item[i]);
        S.insert(res);
        return;
    }
    for (int i = 0; i < caught[depth].size(); i++) {
        bool ok = 1;
        for (int j = 0; j < depth; j++)
            ok &= caught[depth][i] != selected[j];
        if (ok) {
            selected[depth] = caught[depth][i];
            BT(depth + 1);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    N = banned_id.size(), M = user_id.size();
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (cmp(user_id[j], banned_id[i]))
                caught[i].push_back(j);
    BT(0);
    return S.size();
}
