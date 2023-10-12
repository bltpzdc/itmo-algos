#include <iostream>

using namespace std;
int main() {
    int initCount, divideCount, testsCount, maxCount;
    long days;
    cin>>initCount>>divideCount>>testsCount>>maxCount>>days;
    if (initCount * divideCount - testsCount == initCount){
        if (initCount > maxCount){
            cout<<maxCount;
            return 0;
        }
        cout<<initCount;
        return 0;
    }
    for (int i = 0; i < days; i++) {
        initCount *= divideCount;
        if (testsCount >= initCount) {
            cout << 0;
            return 0;
        } else {
            initCount -= testsCount;
        }
        if (initCount > maxCount) {
            cout << maxCount;
            return 0;
        }
    }
    cout<<initCount;
}
