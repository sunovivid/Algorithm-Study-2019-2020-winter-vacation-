#include <iostream>
using namespace std;
int findMaximumSubarray(int arr[], int start, int end);
int findMaximumSubarrayCrossMid(int *pInt, int start, int anEnd, int mid);

#define INF 987654321

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d",findMaximumSubarray(arr,0,n-1));
}

int findMaximumSubarray(int arr[], int start, int end) {
    if (start >= end)
        return arr[start];
    int max = -INF;
    int mid = (start + end)/2;
    int maxLeftHalf = findMaximumSubarray(arr,start,mid);
    if (max < maxLeftHalf)
        max = maxLeftHalf;
    int maxRightHalf = findMaximumSubarray(arr,mid+1,end);
    if (max < maxRightHalf)
        max = maxRightHalf;
    int maxCrossMid = findMaximumSubarrayCrossMid(arr,start,end,mid);
    if (max < maxCrossMid)
        max = maxCrossMid;
    return max;
}

int findMaximumSubarrayCrossMid(int arr[], int start, int end, int mid) {
    //최솟값이 왼쪽에 있는 경우
    int min = INF;
    int leftMax = -INF;
    int leftSum = 0;
    for (int i = mid; i >= 0; i++) {
        if (arr[i] < min)
            min = arr[i];
        leftSum += arr[i];
        if (leftSum / min > leftMax)
            leftMax = leftSum / min;
    }
    min = INF;
    int rightMax = -INF;
    int rightSum = 0;
    for (int i = mid+1; i <= end; i++) {
        if (arr[i] < min)
            min = arr[i];
        rightSum += arr[i];
        if (rightSum / min > rightMax)
            rightMax = rightSum / min;
    }
    if (leftMax + rightSum > rightSum + leftMax)
        return leftMax + rightSum;
    else
        return rightMax + leftSum;

}
