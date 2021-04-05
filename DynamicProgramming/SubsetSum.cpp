#include <iostream>
using namespace std;
int main(){
    int arr[] = {1,8,3,5,7,8,3,2,9,10};
    int sum = 11;
    int n = 10;
    bool dp[n+1][sum+1];
    /*
    * Initialization
    * It is possible to have sum = 0 for arrays of all sizes
    * if we choose null set.
    * 
    * It is not possible to have sum  > 0 for arrays of size 0
    */
    for(int i =0;i<=n;i++){
        for(int j = 0;j<= sum;j++){
            if(i == 0)
                dp[i][j] = false;
            if(j == 0)
                dp[i][j] = true;
        }
    }
    dp[0][0] = true;

    for(int i = 1;i <= n;i++){
        for(int j = 1; j <= sum; j++){
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j- arr[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    if(dp[n][sum])
        cout << "True";
    else
        cout << "False";
}