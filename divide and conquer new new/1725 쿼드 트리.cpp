#include <iostream>

using namespace std;
#define SIZE 64
#define NOTSAME 2
char m[SIZE][SIZE];
char answer[SIZE][SIZE] = {0,};

int getQuadTree(int y, int x, int n) {
    if (n == 1)
        return m[y][x];
    bool isAllElementSame = true;
    for (int i = 0; i < n; i += n / 2) {
        for (int j = 0; j < n; j += n / 2) {
            if (getQuadTree(y + i, x + j, n / 2) != m[y][x]) {
                isAllElementSame = false;
            }
        }
    }
    if (isAllElementSame)
        return m[y][x];
    else {
        answer[y][x]++;
        return NOTSAME; //4개 부분이 같지 않음
    }
}

void printQuadTree(int y, int x, int n) {
    if (n == 1) {
        cout << m[y][x];
        return;
    }
    if (answer[y][x] > 0) {
        answer[y][x]--;
        cout << '(';
        for (int i = 0; i < n; i += n / 2) {
            for (int j = 0; j < n; j += n / 2) {
                printQuadTree(y + i, x + j, n / 2);
            }
        }
        cout << ')';
    }
    else
        cout << m[y][x];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%s", &m[i][0]);
    getQuadTree(0, 0, n);
    printQuadTree(0, 0, n);
    return 0;
}