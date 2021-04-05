#include <iostream>
#include <algorithm>
using namespace std;
int knapsack(int weight[] , int prices[], int maxWeight, int size, int dp[][]){
    if(size == 0 || maxWeight == 0)
        return 0;
    if(dp[size][maxWeight] != -1)
        return dp[size][maxWeight];
    if(weight[size-1] <= maxWeight){
        return dp[size][maxWeight] = max(prices[size-1] + 
        knapsack(weight, prices, maxWeight - weight[size-1], size-1, dp),
        knapsack(weight, prices, maxWeight, size-1, dp));
    }
    return dp[size][maxWeight] = knapsack(weight, prices, maxWeight, size-1, dp);
}
int main(){
    int weight[] = {1,4,5,8};
    int prices[] = {8,1,3,4};
    int n = 4, W = 7;
    int dp[n+1][W+1];
    cout << knapsack(weight, prices, 7, 4, dp);
    return 0;
}