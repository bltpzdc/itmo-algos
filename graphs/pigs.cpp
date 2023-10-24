#include <iostream>
#include <list>
#include <set>

void dfs(std::list<int> graph[], int state[], int &count, int cur, std::set<int> pigs){
    state[cur] = 1;
    pigs.insert(cur);
    for (int i : graph[cur]){
        if (state[i] == 0){
            dfs(graph, state, count, i, pigs);
        }
        else {
            if (pigs.count(i)) count++;
        }
    }
    pigs.erase(cur);
}

int main(){
    int ans = 0, n, key;
    std::cin >> n;
    std::list<int> graph[n];
    std::set<int> pigs;
    int state[n];
    for (int i = 0; i < n; i++){
        std::cin >> key;
        graph[--key].push_back(i);
        state[i] = 0;
    }
    for (int i = 0; i < n; i++){
        if (state[i] == 0){
            dfs(graph, state, ans, i, pigs);
        }
    }
    std::cout << ans;
    return 0;
}