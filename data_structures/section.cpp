#include <iostream>
#include <deque>

int main() {
    int length, window;
    std::cin >> length >> window;
    std::deque<std::pair<int, int>> deq;
    int cur, l = 0;
    for (int i = 0; i < length; i++){
        std::cin >> cur;
        while(!deq.empty() && deq.back().second > cur) deq.pop_back();
        deq.emplace_back(i, cur);
        if (l > deq.front().first) deq.pop_front();
        if (i + 1 >= window){
            l++;
            std::cout << deq.front().second << " ";
        }
    }
    return 0;
}

