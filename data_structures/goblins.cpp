#include <iostream>
#include <list>

std::list<int> first;
std::list<int> second;

void print_goblin(){
    std::cout << first.front() << std::endl;
    first.pop_front();
    if (second.size() > first.size()){
        first.push_back(second.front());
        second.pop_front();
    }
}

void add_common(int num){
    second.push_back(num);
    if (second.size() > first.size()){
        first.push_back(second.front());
        second.pop_front();
    }
}

void add_cool(int num){
    if (first.size() - second.size() == 1){
        second.push_front(num);
    } else {
        first.push_back(num);
    }
}

int main() {
    int count, number;
    char option;
    std::cin >> count;
    for (int i = 0; i < count; i++){
        //std::cout << first.size() << second.size() << std::endl;
        std::cin >> option;
        if (option == '-'){
            print_goblin();
        } else if (option == '+'){
            std::cin >> number;
            add_common(number);
        } else {
            std::cin >> number;
            add_cool(number);
        }
    }
    return 0;
}


