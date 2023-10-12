#include <iostream>
#include <stack>

using namespace std;
int main() {
    string data;
    getline(cin, data);
    stack <char> animsTraps;
    stack <int> anPos, trapPos;
    int anCount = 0, trapCount = 0;
    int order[data.length()/2];
    if (data.length() % 2 != 0 || data == ""){
        cout<<"Impossible";
        return 0;
    }
    for (int i = 0; i < data.length(); i++){
        if (data[i] > 64 && data[i] < 91){
            if (animsTraps.empty() || animsTraps.top()-32 != data[i]){
                animsTraps.push(data[i]);
                trapPos.push(trapCount++);
            } else{
                if (trapCount++ >= data.length()/2){
                    cout<<"Impossible";
                    return 0;
                }
                order[trapCount - 1] = anPos.top();
                animsTraps.pop();
                anPos.pop();
            }
        }
        else{
            if (animsTraps.empty() || animsTraps.top()+32 != data[i]){
                animsTraps.push(data[i]);
                anPos.push(++anCount);
            } else{
                if (trapPos.top()>= data.length()/2){
                    cout<<"Impossible";
                    return 0;
                }
                order[trapPos.top()] = ++anCount;
                animsTraps.pop();
                trapPos.pop();
            }
        }
    }
    if (animsTraps.empty()){
        cout<<"Possible"<<"\n";
        for (int i = 0; i < data.length()/2; i++){
            cout<<order[i]<<" ";
        }
    }
    else {
        cout<<"Impossible";
    }
    return 0;
}
