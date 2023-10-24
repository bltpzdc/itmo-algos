#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int count, k;
    long price = 0;
    cin >> count >> k;
    int products[count];
    for (size_t i = 0; i < count; i++){
        cin >> products[i];
        price += products[i];
    }
    sort(products, products + count);
    for (int i = count - k; i >= 0; i -= k){
        price -= products[i];
    }
    cout << price;
    return 0;
}
