#include <iostream>
using namespace std;

int main() {
    int n,r,c;
    cin >> n; cin >> c; cin >> r;
    n = 1<<n;
    int count = 0;
    while (n > 1) {
        count += (n*n/4) * ((r >= n/2) + (c >= n/2)*2);
        r -= (r >= n/2) * (n/2);
        c -= (c >= n/2) * (n/2);
        n /= 2;
    }
    count += r + c*2;
    cout << count;
    return 0;
}