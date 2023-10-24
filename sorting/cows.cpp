#include <iostream>
#include <algorithm>

using namespace std;

bool check(int mid, int k, int coords[], int n){
    int cows = 1;
    int last = coords[0];
    for (int i = 0; i < n; i++){
        if (coords[i] - last >= mid){
            cows++;
            last = coords[i];
        }
    }
    return cows >= k;
}

int main() {
    int count, cows, left = 0, right, mid;
    cin >> count >> cows;
    int coords[count];
    for (int i = 0; i < count; i++){
        cin >> coords[i];
    }
    right = coords[count - 1] - coords[0] + 1;
    while (right - left > 1){
        mid = (right + left)/2;
        if (check(mid, cows, coords, count)){
            left = mid;
        }
        else {
            right = mid;
        }
    }
    cout << left;
    return 0;
}