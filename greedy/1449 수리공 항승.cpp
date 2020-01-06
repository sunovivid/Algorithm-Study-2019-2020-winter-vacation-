#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, l;
    int spot[1000];
    cin >> n, cin >> l;
    for (int i=0;i<n;i++) {
        cin >> spot[i];
    }
    sort(spot,spot+n);

    int count = 1;
    int taped = spot[0] + l - 1;
    for (int i=0;i<n;i++) {
        if (spot[i] > taped) {
            taped = spot[i] + l - 1;
            count++;
        }
    }
    cout << count;
}
