#include <iostream>
using namespace std;
int main(){
    int arr[] = {1,5,11,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    /*
    * Find the sum of the array
    * If the sum is ODD Return False;
    * 
    * Find using SubsetSum whether a subsequence
    * whose sum is S/2 can be generated
    */

    int sum = 0;
    for(int i =0;i< n;i++)
        sum += arr[i];

    if(sum & 1){
        cout << "False";
        return 0;
    }

    bool dp[n+1][sum/2+1];
    for(int i =0; i <= n; i++){
        for(int j = 0; j <= sum/2; j++){
            if(i == 0)
                dp[i][j] = false;
            if(j == 0)
                dp[i][j] = true;
        }
    }
    dp[0][0] = true;

    for(int i =1; i<= n;i++){
        for(int j = 1; j <= sum/2;j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][sum/2];

}