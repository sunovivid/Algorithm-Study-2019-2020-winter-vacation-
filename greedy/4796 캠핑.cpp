#include <iostream>
using namespace std;

int main() {
    int line = 1;
    while (true) {
        int l, p, v, maxUsingTime = 0;
        cin >> l, cin >> p, cin >> v;
        if (l==0)
            return 0;
        maxUsingTime += (v / p) * l;
        maxUsingTime += (v % p < l) ? (v % p) : l;
        cout << "Case " << line << ": " << maxUsingTime << endl;
        line++;
    }
}
