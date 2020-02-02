#include <iostream>
using namespace std;

int z(int x, int y, int n) {
    if (n == 1)
        return x + y * 2;
    int xQuadrant = x >= n/2; //사분면 나누는 경우 0 index는 경계포함 (이상)
    int yQuadrant = y >= n/2;
    return (n*n/4) * (xQuadrant + yQuadrant*2) + z(x - xQuadrant * (n/2),y - yQuadrant * (n/2), n/2);
}

int main() {
    int n,r,c;
    cin >> n; cin >> r; cin >> c;
    cout << z(c,r,1<<n);
    return 0;
}