#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> c;//finish time, start time
    for (int i=0;i<n;i++) {
        long temp1, temp2;
        scanf("%ld%ld",&temp1,&temp2);
        c.emplace_back(temp1,temp2); //Vector의 v[i]는 read-only, 값 쓰려고 하면 에러남.
    }
    sort(begin(c),end(c),[](auto a, auto b)
    {
        if (a.second != b.second)
            return a.second < b.second;
        else
            return a.first < b.first; //끝나는 시간이 같으면 시작하는 시간 기준으로 정렬! 시작하는 시간과 끝나는 시간이 같은 회의 때문에 꼭 필요
    });
    int lastConfEnd = c[0].second;
    int count = 1;
    for (int i=1;i<n;i++) {
        if (c[i].first >= lastConfEnd) {
            count++;
            lastConfEnd = c[i].second;
        }
    }
    cout << count;
    return 0;
}