#include <iostream>
#include <algorithm>
using namespace std;

bool reverseOrder(int a, int b) {
    return a > b;
}
int main() {
    int n, k;
    cin >> n, cin >> k;
    int coin[n];
    for (int i=0;i<n;i++) {
        scanf("%d",&coin[i]);
    }

    sort(coin,coin+n,reverseOrder);
    int count = 0;
    for (int c : coin) {
        while (k - c >= 0) {
            k -= c;
            count++;
        }
        if (k == 0)
            break;
    }
    cout << count;
}