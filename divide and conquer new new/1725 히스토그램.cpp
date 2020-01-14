#include <iostream>
#include <algorithm>
using namespace std;
int arr[100000];

int getMaximumRectangleCrossingMid(int low, int mid, int high, int n) {
    int left = mid;
    int right = mid+1;
    int h = min(arr[left],arr[right]);
    int midCrossingMax = 2 * h;
    while (left > low || right < high) { //분할된 문제의 경계값을 따르자!!!! ! ! ! !
        if (left == low) {
            right++;
            h = min(h, arr[right]);
        } else if (right == high) {
            left--;
            h = min(h, arr[left]);
        } else {
            if (arr[left - 1] > arr[right + 1]) { //low, high넘어가는지 검사 안해도 되나?? ??
                left--;
                h = min(h, arr[left]);
            } else {
                right++;
                h = min(h, arr[right]);
            }
        }
        int tempArea = (right - left + 1) * h;
        if (midCrossingMax < tempArea)
            midCrossingMax = tempArea;
    }
    return midCrossingMax;
}

int getMaximumRectangle(int low, int high, int n) {
    if (low == high)
        return arr[low];
    int mid = (low + high)/2;
    int max = 0;
    int leftMax = getMaximumRectangle(low,mid,n);
    if (leftMax > max)
        max = leftMax;

    int rightMax = getMaximumRectangle(mid+1,high,n);
    if (rightMax > max)
        max = rightMax;
    int midCrossingMax = getMaximumRectangleCrossingMid(low,mid,high,n);
    if (midCrossingMax > max)
        max = midCrossingMax;
    return max;
}

int main() {
    int n;
    cin >> n;
    for (int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    cout << getMaximumRectangle(0,n-1, n);

}