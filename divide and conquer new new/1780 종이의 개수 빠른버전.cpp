#include <iostream>

using namespace std;
#define SIZE 2187 //3^7

int count[3];//-1,0,1
int p[SIZE][SIZE];

int getNumberOfPaper(int y, int x, int size) {
    if (size == 1) {
        count[p[y][x]+1]++;
        return p[y][x]+1;
    }
    int first = getNumberOfPaper(y,x,size/3);
    bool isFirstOf9BlockSame = true;
    for (int i=0;i<size;i+=size/3) {
        for (int j=0;j<size;j+=size/3) {
            if (getNumberOfPaper(y+i,x+j,size/3) != first)
                isFirstOf9BlockSame = false;
        }
    }
    if (isFirstOf9BlockSame)
        count[first]

}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &p[i][j]);
    }
    getNumberOfPaper(0, 0, n);
    cout << count[0] << endl << count[1] << endl << count[2];
    return 0;
}