#include <iostream>
using namespace std;

int getDecompositionSum(int n) {
    int result = n;
    while (n > 0) {
        result += n%10;
        n /= 10;
    }
    return result;
}

int main(void) {
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) {
        if (getDecompositionSum(i) == n) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}

