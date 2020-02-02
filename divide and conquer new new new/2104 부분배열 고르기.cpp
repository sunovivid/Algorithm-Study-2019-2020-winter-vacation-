#include <iostream>
#include <algorithm>
using namespace std;
unsigned long long findMaximumSubarray(const unsigned long long arr[], int start, int end);
unsigned long long findMaximumSubarrayCrossMid(const unsigned long long arr[], int start, int end, int mid);

#define INF 987654321
#define LONGINF 987654321


unsigned long long min(unsigned long long a, unsigned long long b) {
    return a < b ? a : b;
}
unsigned long long max(unsigned long long a, unsigned long long b) {
    return a > b ? a : b;
}

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
    int l = mid, r = mid+1;
    unsigned long long m = min(arr[l],arr[r]);
    unsigned long long sum = arr[l]+arr[r];
    unsigned long long maxScore = m  * sum;
    while (l > start || r < end) {
        if (l == start) {
            r++;
            sum += arr[r];
            m = min(m,arr[r]);
        } else if (r == end) {
            l--;
            sum += arr[l];
            m = min(m,arr[l]);
        } else {
            if (min(m,arr[l-1])*(sum+arr[l-1]) > min(m,arr[r+1])*(sum+arr[r+1])) {
                l--;
                sum += arr[l];
                m = min(m,arr[l]);
            } else {
                r++;
                sum += arr[r];
                m = min(m,arr[r]);
            }
        }
        maxScore = max(maxScore, m*sum);
    }
    return maxScore;
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