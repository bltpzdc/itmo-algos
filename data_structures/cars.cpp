#include <iostream>
#include <list>
#include <unordered_set>
#include <queue>

int main() {
    int n, k, p;
    std::cin >> n >> k >> p;
    int order[p];
    std::list<int> cars_positions[n];
    for (int i = 0; i < p; i++){
        std::cin >> order[i];
        order[i]--;
        cars_positions[order[i]].push_back(i);
    }
    std::unordered_set<int> on_floor;
    std::priority_queue<std::pair<int, int>> next_for_up;
    int ans = 0;
    for (int i = 0; i < p; i++){
        int car = order[i];
        if (on_floor.count(car) == 0){
            if (on_floor.size() >= k){
                on_floor.erase(next_for_up.top().second);
                next_for_up.pop();
            }
            on_floor.insert(car);
            ans++;
        }
        cars_positions[car].pop_front();
        if (cars_positions[car].empty()) next_for_up.push({p + 1, car});
        else next_for_up.push({cars_positions[car].front(), car});
    }
    std::cout << ans;
    return 0;
}


