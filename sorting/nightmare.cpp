#include <iostream>
#include <algorithm>
#include "cstring"

using namespace std;
int weights[26];

bool comparator(const char &first, const char &second) {
    if (weights[first - 'a'] == weights[second - 'a']) return first > second;
    return weights[first - 'a'] > weights[second - 'a'];
}

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < 26; i++) {
        cin >> weights[i];
    }
    sort(s.begin(), s.end(), comparator);
    string start = "", middle = "";
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == s[i + 1] && (!start.empty() && start.at(start.length() - 1) != s[i] || start.empty())) {
            start += s[i++];
        } else middle += s[i];
    }
    if (start.length() * 2 + middle.length() < s.length()) {
        middle += s[s.length() - 1];
    }
    cout << start << middle;
    for (int i = start.length() - 1; i >= 0; i--) {
        cout << start[i];
    }
    return 0;
}

