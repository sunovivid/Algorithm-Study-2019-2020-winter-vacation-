//무한루프 돌아서 오버플로 나는 경우였음. Segmentation Fault -> 무한 루프일 경우도 의심.

#include <iostream>
#include <algorithm>
using namespace std;
int arr[100000];

int getMaximumRectangleCrossingMid(int low, int mid, int high, int n) {
    int x = arr[mid];
    int xx = arr[mid+1];
    int mintest = min(x,xx);
    int asdf = (x<xx)?x:xx;
    int maxtest = max(x,xx);
    int sadfas = (x>xx)?x:xx;
    int y = min(1,2);
    int h = min(x,xx);
    int height = 1;
    int midCrossingMax = 2 * height;
    int left = mid;
    int right = mid + 1;
    while (left > low || right < high) { //분할된 문제의 경계값을 따르자!!!! ! ! ! !
        if (arr[max(left-1,low)] > arr[min(right+1,high)]) { //low, high넘어가는지 검사 안해도 되나?? ??
            left--;
            height = min(height, arr[left]);
        }
        else {
            right++;
            height = min(height, arr[right]);
        }
        int tempArea = (right - left + 1) * height;
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