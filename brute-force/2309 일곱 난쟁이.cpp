#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main (void) {
    int height[9];
    vector<int> heightOf7;
    int sum = 0;
    for (int i=0;i<9;i++) {
        cin >> height[i];
        sum += height[i];
    }

    int i,j;
    for (i=0;i<9;i++) {
        for (j=0;j<9;j++) {
            if (i != j) {
                if (sum - (height[i] + height[j]) == 100) {
                    goto out;
                }
            }
        }
    }
    out:

    for (int k=0;k<9;k++) {
        if (k != i && k != j) {
            heightOf7.push_back(height[k]);
        }
    }
    
    sort(heightOf7.begin(),heightOf7.end());
    for (int h : heightOf7) {
        cout << h << endl;
    }

    return 0;
}