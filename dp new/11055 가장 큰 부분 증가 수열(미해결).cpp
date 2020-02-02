#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][1001] = {0,};
int sum[1001][1001] = {0,};

int main() {
    int N;
    cin >> N;
    int first;
    cin >> first;
    int size = first;
    dp[first][0] = first;
    sum[first][0] = first;
    for (int i = 1; i < N; i++) {
        int c;
        cin >> c;
        int maxSum = 0;
        for (int j = 1; j < c; j++) {
            if (dp[j][i - 1] != 0) {
                dp[j][i] = dp[j][i - 1];
                sum[j][i] = sum[j][i - 1];
            } else if (c > size) {
                dp[j][i] = dp[size][i - 1];
                sum[j][i] = sum[size][i - 1];
            }
            maxSum = max(maxSum,sum[j][i - 1]);
        }
        for (int j = c; j <= size; j++) {
            dp[j][i] = dp[j][i - 1];
            sum[j][i] = sum[j][i - 1];
        }
        size = max(size, c);
        dp[c][i] = c;
        sum[c][i] = maxSum + c;

        cout << maxSum + c << ' ';
    }

    int resultMaxSum = 0;
    for (int j = 1; j <= size; j++) {
        resultMaxSum = max(resultMaxSum, sum[j][N - 1]);
    }
    cout << resultMaxSum;
}

