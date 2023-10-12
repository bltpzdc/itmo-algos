#include <iostream>

using namespace std;

int main()
{
    long count;
    cin>>count;

    if (count == 1){
        cout<<1<<" "<<1;
        return 0;
    }
    if (count == 2){
        cout<<1<<" "<<2;
        return 0;
    }

    int maxLen = 2, curLen = 2, start = 1, curStart = 1, end = 2, curFlower;
    int flowers[2];
    cin>>flowers[0]>>flowers[1];

    for (int i = 2; i < count; i++){
        cin>>curFlower;
        if (curFlower == flowers[0] && flowers[0] == flowers[1]){
            if (maxLen < curLen){
                maxLen = curLen;
                start = curStart;
                end = i;
            }
            curStart = i;
            curLen = 2;
        }
        else {
            curLen++;
            flowers[0] = flowers[1];
            flowers[1] = curFlower;
        }
    }

    if (curLen > maxLen){
        start = curStart;
        end = count;
    }
    cout<<start<<" "<<end;
    return 0;
}