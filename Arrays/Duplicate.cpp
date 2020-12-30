// Time Complexity :    O(N)
// Space Somplexity :   O(1) 

// https://medium.com/solvingalgo/solving-algorithmic-problems-find-a-duplicate-in-an-array-3d9edad5ad41
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n+1];
    for (int i =0;i<n+1;i++)
        cin >> arr[i];
    
    // Given 1 <= a[i] <= n
    int dupl = 0;
    for(int i =0;i<n+1;i++){
        if(arr[abs(arr[i])] < 0){
            dupl = abs(arr[i]);
            break;
        }
        else{
            arr[abs(arr[i])] *= -1;
        }
    }

    cout << dupl;

}