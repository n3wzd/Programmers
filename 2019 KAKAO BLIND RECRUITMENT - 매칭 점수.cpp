#include <string>
#include <vector>
#include <regex>
#include <map>
#include <cctype>
using namespace std;
int N; double wordScore[20], linkScore[20];
string myLink[20];
vector<string> hyperlink[20];
map<string, int> linkToIdx;

int getMaxScore() {
    double maxScore = -1; int res = 0;
    for (int i = 0; i < N; i++)
        for (auto s : hyperlink[i])
            if (linkToIdx.find(s) != linkToIdx.end())
                linkScore[linkToIdx[s]] += wordScore[i] / hyperlink[i].size();
    for (int i = 0; i < N; i++) {
        double score = wordScore[i] + linkScore[i];
        if (score > maxScore) {
            maxScore = score;
            res = i;
        }
    }
    return res;
}

int solution(string word, vector<string> pages) {
    N = pages.size();
    for (int i = 0; i < N; i++) {
        auto page = pages[i];
        regex pattern1(R"(<a href=\"([^\"]+)\")");
        sregex_iterator iter1(page.begin(), page.end(), pattern1);
        sregex_iterator end;
        while (iter1 != end) {
            hyperlink[i].push_back(iter1->str(1));
            iter1++;
        }

        regex pattern2(R"(<meta\s+[^>]*content=\"([^\"]+)\")");
        sregex_iterator iter2(page.begin(), page.end(), pattern2);
        myLink[i] = iter2->str(1);
        linkToIdx[myLink[i]] = i;

        regex pattern3("(" + word + ")", regex_constants::icase);
        sregex_iterator iter3(page.begin(), page.end(), pattern3);
        while (iter3 != end) {
            int p = iter3->position();
            if (!isalpha(page[p - 1]) && !isalpha(page[p + word.size()]))
                wordScore[i]++;
            iter3++;
        }
    }
    return getMaxScore();
}
