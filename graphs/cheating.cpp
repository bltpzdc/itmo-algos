#include <iostream>
#include <list>

struct Node{
    std::list<int> nodes;
    int color;
};

bool dfs(Node nodes[], int cur, int color){
    nodes[cur].color = color;
    for (int i : nodes[cur].nodes){
        if (nodes[i].color == 0){
            if (!dfs(nodes, i, color == 1 ? 2 : 1)) return false;
        } else if (nodes[i].color == color) return false;
    }
    return true;
}

int main(){
    int n, m, fir, sec;
    bool ans = true;
    std::cin >> n >> m;
    Node nodes[n];
    for (int i = 0; i < m; i++){
        std::cin >> fir >> sec;
        --fir;
        --sec;
        nodes[fir].nodes.push_back(sec);
        nodes[sec].nodes.push_back(fir);
    }
    for (int i = 0; i < n; i++){
        nodes[i].color = 0;
    }
    for (int i = 0; i < n; i++){
        if (!ans) break;
        if (nodes[i].color == 0) ans = dfs(nodes, i, 1);
    }
    std::string output = ans ? "YES" : "NO";
    std::cout << output;
}