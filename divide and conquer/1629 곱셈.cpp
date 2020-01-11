#include <iostream>

unsigned long long getRemainderOfPower(unsigned long long a, int b, int c);
using namespace std;

int main() {
    unsigned long long a, b, c;
    scanf("%llu%llu%llu",&a,&b,&c);
    printf("%llu",getRemainderOfPower(a,b,c));
    return 0;
}

unsigned long long getRemainderOfPower(unsigned long long a, int b, int c) {
    if (b == 1)
        return a % c;
    else {
        if (b % 2 == 0) {
            unsigned long long temp = getRemainderOfPower(a,b/2,c);
            return (temp * temp) % c;
        }
        else {
            //return ((a % c) * getRemainderOfPower(a,b-1,c))%c; //working

            unsigned long long temp = getRemainderOfPower(a,b/2,c);
            return ((a % c) * temp * temp) % c; //not working
        }
    }
}