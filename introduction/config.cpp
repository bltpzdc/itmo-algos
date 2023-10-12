#include <iostream>
#include <fstream>
#include <map>
#include <stack>

using namespace std;
int main() {
    string  line;
    map <string, stack<long>> variables;
    stack <string> history;
    int level = 0, position;
    long varValue;
    string elements[2];
    while (cin>>line){
        if (line == "{"){
            history.push(to_string(++level));
        }
        else if (line == "}"){
            while (history.top() != to_string(level)){
                variables[history.top()].pop();
                history.pop();
            }
            history.pop();
            level--;
        }
        else {
            position = line.find('=');
            elements[0] = line.substr(0, position);
            elements[1] = line.substr(position + 1);
            if (!variables.count(elements[0])) variables[elements[0]] = stack <long>{};
            if (elements[1][0] == '-' || elements[1][0] >= '0' && elements[1][0] <= '9'){
                if (variables[elements[0]].size() == level + 1){
                    variables[elements[0]].pop();
                    variables[elements[0]].push(stoi(elements[1]));
                }
                else {
                    variables[elements[0]].push(stoi(elements[1]));
                    history.push(elements[0]);
                }
            }
            else {
                if (variables.count(elements[1]) && !variables[elements[1]].empty()){
                    varValue = variables[elements[1]].top();
                }
                else {
                    varValue = 0;
                }
                cout<<varValue<<"\n";
                if (variables[elements[0]].size() == level + 1){
                    variables[elements[0]].pop();
                    variables[elements[0]].push(varValue);
                }
                else {
                    variables[elements[0]].push(varValue);
                    history.push(elements[0]);
                }
            }
        }
    }
    return 0;
}

