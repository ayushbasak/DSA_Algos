#include <iostream>
#include <algorithm>
using namespace std;
int knapsack(int weight[] , int prices[], int maxWeight, int size){
    if(size == 0 || maxWeight == 0)
        return 0;
    if(weight[size-1] <= maxWeight){
        return max(prices[size-1] + 
        knapsack(weight, prices, maxWeight - weight[size-1], size-1),
        knapsack(weight, prices, maxWeight, size-1));
    }
    return knapsack(weight, prices, maxWeight, size-1);
}
int main(){
    int weight[] = {1,4,5,8};
    int prices[] = {8,1,3,4};
    cout << knapsack(weight, prices, 7, 4);
    return 0;
}