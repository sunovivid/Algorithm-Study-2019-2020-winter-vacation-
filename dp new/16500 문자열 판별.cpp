#include <iostream>
#include <algorithm>

using namespace std;

//bool operator <(const string &a, const string &b) {
//    return ;
//}

int main() {
    string s;
    getline( cin, s );
    int n;
    cin >> n;
    string a[n];
    getline(cin,a[0]);
    for (int i=0;i<n;i++) {
        getline(cin,a[i]);
    }
    sort(a,a+n);
    while (true) {
        string comp = (*lower_bound(a, a + n, s));
        if (s.find(comp) == 0) {
            s = s.substr(comp.size(),-31);
            if (s.empty()) {
                cout << '1';
                return 0;
            }
        } else {
            cout << '0';
            return 0;
        }
    }
}