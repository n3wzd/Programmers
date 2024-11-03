#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <regex>
using namespace std;

string solution(string id) {
    transform(id.begin(), id.end(), id.begin(), ::tolower);
    id = regex_replace(id, regex("[^a-z0-9._-]+"), "");
    id = regex_replace(id, regex("\\.+"), ".");
    id = regex_replace(id, regex("^\\.|\\.$"), "");
    if (id.empty()) id = "a";
    if (id.size() > 15) id = id.substr(0, 15);
    if (id.back() == '.') id.pop_back();
    while (id.size() < 3) id += id[id.size() - 1];
    return id;
}
