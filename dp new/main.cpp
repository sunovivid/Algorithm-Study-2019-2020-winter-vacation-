#include <iostream>
using namespace std;

int item[100][2]; //W, V
int dp[100][100000];

int f(int i, int limit) {
    if (dp[i][limit] != -1)
        return dp[i][limit];
    if (limit < item[i][0])
        return f(i+1,limit);
    else
        return max(f(i+1,limit-item[i][0])+item[i][1],f(i+1,limit));
}

int main () {
    int n, k;
    cin >> n;
    cin >> k;
    for (int i=0;i<n;i++) {
        cin >> item[i][0];
        cin >> item[i][1];
    }
    //fill_n(dp,10000000,-1); error 1
    memset
    cout << f(0,k);
}