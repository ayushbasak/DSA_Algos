// Time Complexity: O(log min(a,b))

#include <iostream>
using namespace std;
int gcd(int a, int b){
    return b==0 ? a: gcd(b, a%b);
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}
int main(){
    int a = 8123, b = 82;
    cout << gcd(a,b)<< endl;
    cout << lcm(a,b) << endl;
}

//https://cp-algorithms.com/algebra/euclid-algorithm.html