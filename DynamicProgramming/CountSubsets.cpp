#include <iostream>
using namespace std;
int main(){
    int arr[] = {2,3,5,6,8,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout  << n << endl;
    int target = 10;
    int dp[n+1][target+1];

    for(int i =0;i<= n;i++){
        for(int j =0;j<= target;j++){
            if(i == 0)  dp[i][j] = 0;
            if(j == 0)  dp[i][j] = 1;
        }
    }
    dp[0][0] = 1;

    for(int i =1 ;i<=n;i++){
        for(int j = 1; j<= target; j++){
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j - arr[i-1]] + dp[i-1][j];
            else    dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][target];

}