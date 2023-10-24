#include <iostream>
#include <map>

std::multimap<int, int> size_index;
std::map<int, int> index_size;

void remove_by_size(const std::map<int, int>::iterator& it){
    auto rm = size_index.find(it->second);
    while (rm->second != it->first) rm++;
    size_index.erase(rm);
    index_size.erase(it);
}
void insert(const std::pair<int, int>& pair){
    index_size.insert(pair);
    size_index.insert({pair.second, pair.first});
}

int main() {
    int n, m, k, index, size;
    std::cin >> n >> m;
    std::pair<int, int> history[m];
    insert({1, n});
    for (int i = 0; i < m; i++){
        std::cin >> k;
        if (k > 0) {
            auto it = size_index.lower_bound(k);
            if (it == size_index.end()) index = -1;
            else {
                index = it->second;
                size = it->first - k;
                index_size.erase(it->second);
                size_index.erase(it);
                if (size > 0) insert({index + k, size});
            }
            std::cout << index << std::endl;
        } else {
            int remove_index = history[abs(k) - 1].second;
            int remove_size = history[abs(k) - 1].first;
            if (remove_index == -1) continue;
            auto right_free = index_size.lower_bound(remove_index);
            auto left_free = (right_free != index_size.begin()) ? prev(right_free) : index_size.end();
            if (right_free != index_size.end() && right_free->first == remove_index + remove_size){
                if (left_free != index_size.end() && left_free->first + left_free->second == remove_index) {
                    index = left_free->first;
                    size = left_free->second + right_free->second;
                    remove_by_size(left_free);
                    remove_by_size(right_free);
                    insert({index, size + remove_size});
                } else {
                    size = right_free->second;
                    remove_by_size(right_free);
                    insert({remove_index, size + remove_size});
                }
            } else {
                if (left_free != index_size.end() && left_free->first + left_free->second == remove_index) {
                    index = left_free->first;
                    size = left_free->second;
                    remove_by_size(left_free);
                    insert({index, size + remove_size});
                } else insert({remove_index, remove_size});
            }
            index = 0;
        }
        history[i] = {k, index};
    }
    return 0;
}