#include <iostream>
#include <algorithm>

using namespace std;
int dp[1000][1000];
int arr[1000];

int f(int i, int j) {
    if (i == 0)
        return j <= arr[0] ? arr[0] : -INT32_MAX;
    if (dp[i][j] != 0)
        return dp[i][j];
    int result = 0;
    for (int k = 0; k < j; k++) {
        result = max(result, f(i-1, k) + arr[i]);
    }    dp[i][j] = result;
    return result;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    cout << f(N, arr[N]);
    return 0;
}
