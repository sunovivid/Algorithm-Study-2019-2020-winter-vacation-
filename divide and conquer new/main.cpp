#include <iostream>
using namespace std;
unsigned long long findMaximumSubarray(const unsigned long long arr[], int start, int end);
unsigned long long findMaximumSubarrayCrossMid(const unsigned long long arr[], int start, int end, int mid);

#define INF 987654321
#define LONGINF 987654321

int main() {
    int n; cin >> n;
    unsigned long long arr[n];
    for (int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);
    printf("%llu",findMaximumSubarray(arr,0,n-1));
}

unsigned long long findMaximumSubarray(const unsigned long long arr[], const int start, const int end) {
    if (start >= end)
        return arr[start]*arr[start];
    unsigned long long max = 0;
    int mid = (start + end)/2;
    unsigned long long maxLeftHalf = findMaximumSubarray(arr,start,mid);
    if (max < maxLeftHalf)
        max = maxLeftHalf;
    unsigned long long maxRightHalf = findMaximumSubarray(arr,mid+1,end);
    if (max < maxRightHalf)
        max = maxRightHalf;
    unsigned long long maxCrossMid = findMaximumSubarrayCrossMid(arr,start,end,mid);
    if (max < maxCrossMid)
        max = maxCrossMid;
    return max;
}

unsigned long long findMaximumSubarrayCrossMid(const unsigned long long arr[], const int start, const int end, const int mid) {
    unsigned long long leftMin = INF;
    unsigned long long leftMinRecord = INF;
    unsigned long long leftScoreMax = 0;
    unsigned long long leftSum = 0;
    for (int i = mid; i >= start; i--) { //i--를 i++로 씀..
        if (arr[i] < leftMin)
            leftMin = arr[i];
        leftSum += arr[i];
        if (leftSum * leftMin > leftScoreMax) {
            leftScoreMax = leftSum * leftMin;
            leftMinRecord = leftMin;
        }
    }
    unsigned long long rightMin = INF;
    unsigned long long rightMinRecord = INF;
    unsigned long long rightScoreMax = 0;
    unsigned long long rightSum = 0;
    for (int i = mid+1; i <= end; i++) {
        if (arr[i] < rightMin)
            rightMin = arr[i];
        rightSum += arr[i];
        if (rightSum * rightMin > rightScoreMax) {
            rightScoreMax = rightSum * rightMin;
            rightMinRecord = rightMin;
        }
    }
    return ((leftScoreMax / leftMinRecord) + (rightScoreMax / rightMinRecord)) * (leftMinRecord<rightMinRecord?leftMinRecord:rightMinRecord);
}

////최솟값이 왼쪽에 있는 경우
//int min = INF;
//int leftMax = -INF;
//int leftSum = 0;
//for (int i = mid; i >= 0; i--) { //i--를 i++로 씀..
//if (arr[i] < min)
//min = arr[i];
//leftSum += arr[i];
//if (leftSum * min > leftMax)
//leftMax = leftSum * min;
//}
//min = INF;
//int rightMax = -INF;
//int rightSum = 0;
//for (int i = mid+1; i <= end; i++) {
//if (arr[i] < min)
//min = arr[i];
//rightSum += arr[i];
//if (rightSum * min > rightMax)
//rightMax = rightSum * min;
//}
//if (leftMax + rightSum > rightSum + leftMax)
//return leftMax + rightSum;
//else
//return rightMax + leftSum;