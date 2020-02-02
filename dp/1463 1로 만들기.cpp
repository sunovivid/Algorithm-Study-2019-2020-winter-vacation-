#include <iostream>

using namespace std;
int dp[1000000] = {0,};

void makeOne(int n);

int getDPWithMemoization(int n) {
    if (n < 1)
        return INT32_MAX;
    else if (n == 1)
        return 0;
    if (dp[n] == 0)
        makeOne(n);
    return dp[n];
}

void makeOne(int n) {
    if (n <= 1)
        return;
    int temp[3] = {INT32_MAX,INT32_MAX,INT32_MAX};
    if (n % 3 == 0)
        temp[0] = getDPWithMemoization(n/3) + 1;
    if (n % 2 == 0)
        temp[1] = getDPWithMemoization(n/2) + 1;
    temp[2] = getDPWithMemoization(n-1) + 1;
    dp[n] = min(temp[0],min(temp[1],temp[2]));
}

int main() {
    int n;
    cin >> n;
    dp[1] = 0;
    makeOne(n);
    cout << dp[n];
    return 0;
}
