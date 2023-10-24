#include <iostream>
#include <algorithm>
#include "vector"

using namespace std;

bool comparator(const string& first, const string& second){
    return first + second < second + first;
}

int main() {
    vector<string> nums;
    string cur, answer;
    while (cin >> cur){
        nums.push_back(cur);
    }
    sort(nums.begin(), nums.end(), comparator);
    for (int i = nums.size() - 1; i >= 0; i--){
        answer += nums.at(i);
    }
    cout << answer;
    return 0;
}
