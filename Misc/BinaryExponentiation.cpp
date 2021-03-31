// Time Complexity: O(log n)
#include <iostream>
using namespace std;
long long binpow(long long a, long long n){
    if(n == 0)
        return 1;
    long long res = binpow(a,n/2);
    if(n & 1)
        return res * res * a;
    return res * res;
}
long long binpowIterative(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1; //divide by 2
    }
    return res;
}
int main(){
    long long x = 200, y = 5;
    cout << binpow(x,y) << endl;
    cout << binpowIterative(x,y) << endl;
}