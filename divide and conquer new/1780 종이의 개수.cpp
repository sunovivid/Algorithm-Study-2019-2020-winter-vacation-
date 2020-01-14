#include <iostream>

using namespace std;
#define SIZE 2187 //3^7

void getNumberOfPaper(int xs, int ys, int size);

int count[3];//-1,0,1
int p[SIZE][SIZE];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &p[i][j]);
    getNumberOfPaper(0, 0, n);
    cout << count[0] << endl << count[1] << endl << count[2];
    return 0;
}

void getNumberOfPaper(int xs, int ys, int size) {
    int before = p[xs][ys];
    for (int k = 0; k < size/3; k++) {
        for (int l = 0; l < size/3; l++) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int now = p[xs + i*size/3 + k][ys + j*size/3 + l];
                    if (now != before) {
                        for (int a=0;a<9;a++)
                            getNumberOfPaper(xs+a/3*size/3,ys+a%3*size/3,size/3);
                        return;
                    }
                    before = now;
                }
            }
        }
    }
    count[p[xs][ys] + 1]++;
}
