#include <iostream>

int graph[1001][1001];
bool visited[1001], g[1001][1001];

void dfs(int v, int type, int n) {
    visited[v] = true;
    for(int i = 0; i < n; i++)
        if ((type ? g[i][v] : g[v][i]) && !visited[i]) dfs(i,type, n);
}

bool check(int n) {
    for(int i = 0; i < n; i++)
        if (!visited[i]) return false;
    return true;
}

int main(){
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            std::cin >> graph[i][j];
    int min = 0, max = INT32_MAX, mid;
    while(min < max) {
        mid = (min + max) / 2;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                g[i][j] = (graph[i][j] <= mid);
        for (int i = 0; i < n; i++)
            visited[i] = false;
        dfs(0, 0, n);
        bool flag = false;
        if (check(n)){
            for (int i = 0; i < n; i++)
                visited[i] = false;
            dfs(0, 1, n);
            if (!check(n)) flag = true;
        } else flag = true;
        if (flag) min = mid + 1;
        else max = mid;
    }
    std::cout << min;
}