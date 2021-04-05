#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int weight[] = {1,4,5,8};
    int prices[] = {8,1,3,4};
    int n = 4, W = 7;
    int dp[n+1][W+1];

    // Initialisation
    for(int i =0;i <= n;i++){
        for(int j = 0;j <= W; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    
    for(int i = 1;i <= n; i++){
        for(int j = 1;j <= W; j++){
            if(weight[i-1] <= j){
                dp[i][j] = max(prices[i-1] + dp[i-1][j- weight[i-1]],
                                dp[i-1][j]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][W];
}