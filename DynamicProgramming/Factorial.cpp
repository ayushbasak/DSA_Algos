#include <iostream>
#define ull unsigned long long int
using namespace std;
ull factorial(int n, ull dp[]){
    if(n == 0)
        return 1;
    if(dp[n] != -1)
        return dp[n];
    return dp[n] = n*factorial(n-1, dp);
}
int main(){
    int c = 15;
    ull dp[c+1];
    for(int i =0;i<=c;i++)
        dp[i] = -1;
    cout << factorial(c, dp);
    return 0;
}