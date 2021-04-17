#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comparator(pair<int, int>& A, pair<int, int>& B){
    double x = (double)A.second/(double)A.first;
    double y = (double)B.second/(double)B.first;
    return x > y;
}
int main(){
    vector<int> weights = {10,20,30};
    vector<int> prices = {60,100,120};
    double maxWeight = 50.0;
    int size = sizeof(weights)/sizeof(weights[0]);
    vector<pair<int, int>> base;
    for(int i =0;i<size;i++)
        base.push_back(make_pair(weights[i], prices[i]));
    
    sort(base.begin(), base.end(), comparator);
    double maxProfit = 0;
    for(int i =0; i<size; i++){
        if(maxWeight <= 0)
            break;
        if(base[i].first <= maxWeight){
            maxWeight -= base[i].first;
            maxProfit += base[i].second;
        }
        else{
            maxProfit += (maxWeight/base[i].first)*base[i].second;
            maxWeight = 0.0;
        }
    }
    
    cout << "Maximum Profit : " << maxProfit << endl;
            
    
    return 0;
}