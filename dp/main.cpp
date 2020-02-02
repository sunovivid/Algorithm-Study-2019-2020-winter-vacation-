#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001][1001] = {0,};
int sum[1001][1001] = {0,};
int main() {
    int N;
    cin >> N;
    int size = 0;
    cin >> c;
    for (int j=1;j<=c;j++) {
        dp[j][0] = c;
        sum[j][0] = c;
    }
    for (int i=1;i<N;i++) {
        cin >> c;
        int maxSum = 0;
        for (int j=1;j<=c;j++) {
            if (dp[j][i-1] != 0) {
                dp[j][i] = dp[j][i-1];
                sum[j][i] = sum[j][i-1];
            } else {
                dp[j][i] = dp[size][i-1];
                sum[j][i] = sum[size][i-1];
            }
            if (maxSum < sum[j][i-1]) {
                maxSum = sum[j][i-1];
            }
        }
        size = max(size,c);
        for (j=c+1;j<=size;j++) {
            dp[j][i] = dp[j][i-1];
            sum[j][i] = sum[j][i-1];
        }
        sum[c][i] = maxSum + c;
    }

    int maxSum = 0;
    for (int j=1;j<=size;j++) {
        maxSum = max(maxSum, sum[j][N-1]);
    }
    cout << maxSum;
}
















































































