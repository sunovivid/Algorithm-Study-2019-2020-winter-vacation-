#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <list>

using namespace std;

int main() {
    int n, k;
    cin >> n, cin >> k;
    vector<int> v;
    list<int> toolUsingNow;
    for (int i=0;i<k;i++) {
        int temp;
        scanf("%d",&temp);
        v.emplace_back(temp);
    }

    int count = 0;
    for (int i=0;i<k;i++) {
        bool isAlreadyIn = false;
        for (int t : toolUsingNow)
            if (v[i] == t)
                isAlreadyIn = true;
        if (!isAlreadyIn)
        {
            if (toolUsingNow.size() >= n) {
                count++;
                int timeGapToNextUse[100];
                fill_n(timeGapToNextUse,100,987654321);
                int maxTimeGapToNextUse = -1;
                int lastUseTool = -1;
                for (int tool : toolUsingNow) {
                    for (int j=i+1;j<k;j++) {
                        if (tool == v[j]) {
                            timeGapToNextUse[tool] = j - i;
                            break;
                        }
                    }
                    if (timeGapToNextUse[tool] > maxTimeGapToNextUse) {
                        maxTimeGapToNextUse = timeGapToNextUse[tool];
                        lastUseTool = tool;
                    }//경계값으로 INF를 설정하고 for문으로 최댓값을 탐색할 때,
                    //"최댓값 갱신 코드는 for문 밖에 있어야" 경계값이 최댓값인 경우(for문에서 탐색 실패한 경우) 최댓값이 갱신된다.
                }
                toolUsingNow.remove(lastUseTool);
            }
            toolUsingNow.push_back(v[i]);
        }
    }
    cout << count;
}