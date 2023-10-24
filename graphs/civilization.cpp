#include <iostream>
#include <queue>
#include <deque>
#include <vector>

struct node{
    int x;
    int y;
    int fromX;
    int fromY;
    int time;
};

class Compare{
public:
    bool operator()(struct node& first, struct node& second){
        return first.time > second.time;
    }
};

int main(){
    int n, m, startX, startY, endX, endY;
    std::cin >> n >> m >> startX >> startY >> endX >> endY;
    std::string map[n];
    for (int i = 0; i < n; i++) std::cin >> map[i];
    node graph[n][m];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) graph[i][j] = {i, j,  -1, -1, -1};
    graph[startX - 1][startY - 1].time = 0;
    std::priority_queue<node, std::vector<node>, Compare> visits;
    visits.push(graph[startX - 1][startY - 1]);
    while (!visits.empty()){
        node cur = visits.top();
        visits.pop();
        int x = cur.x;
        int y = cur.y;

        if (x == endX && y == endY) break;
        if (map[x][y] == '#') continue;

        std::vector<node> neighbours;
        if (x - 1 >= 0 && map[x - 1][y] != '#') neighbours.push_back({cur.x - 1, cur.y, cur.x, cur.y, map[x - 1][y] == '.' ? 1 : 2});
        if (x + 1 < n && map[x + 1][y] != '#') neighbours.push_back({cur.x + 1, cur.y, cur.x, cur.y, map[x + 1][y] == '.' ? 1 : 2});
        if (y - 1 >= 0 && map[x][y - 1] != '#') neighbours.push_back({cur.x, cur.y - 1, cur.x, cur.y, map[x][y - 1] == '.' ? 1 : 2});
        if (y + 1 < m && map[x][y + 1] != '#') neighbours.push_back({cur.x, cur.y + 1, cur.x, cur.y, map[x][y + 1] == '.' ? 1 : 2});

        for (const node& i : neighbours){
            int bw_time = cur.time + i.time;
            if (bw_time < graph[i.x][i.y].time || graph[i.x][i.y].time == -1){
                graph[i.x][i.y].time = bw_time;
                graph[i.x][i.y].fromX = cur.x;
                graph[i.x][i.y].fromY = cur.y;
                visits.push(graph[i.x][i.y]);
            }
        }
    }
    std::cout << graph[endX - 1][endY - 1].time << std::endl;
    if (graph[endX - 1][endY - 1].time == -1) return 0;
    std::deque<char> steps;
    int x = endX - 1, y = endY - 1;
    while (x != startX - 1 || y != startY - 1){
        int diffX = x - graph[x][y].fromX;
        int diffY = y - graph[x][y].fromY;
        if (diffX == 1) steps.push_front('S');
        if (diffX == -1) steps.push_front('N');
        if (diffY == 1) steps.push_front('E');
        if (diffY == -1) steps.push_front('W');
        x = x - diffX;
        y = y - diffY;
    }
    for (const char& i : steps) std::cout << i;
    return 0;
}