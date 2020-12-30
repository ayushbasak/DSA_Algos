// Time Complexity :    O(Log(m*n))
// Space Complexity :   O(1)
#include <iostream>
#include <tuple>
using namespace std;
tuple<int, int> index(int pos, int col_size){
    tuple<int, int> arr = {pos/ col_size, pos% col_size};
    return arr; 
}
int main(){
    int m,n;
    cin >> m >> n;
    int arr[m][n];
    for(int i =0;i<m;i++){
        for(int j =0;j<n;j++)
            cin >> arr[i][j];
    } 
    int elem;
    cin >> elem;
    int low = 0, high = m*n-1;
    while(low <= high){
        int mid = (low + high)/2;
        tuple<int, int> deref = index(mid, n);

        if(arr[get<0>(deref)][get<1>(deref)] == elem){
            cout << "\nFOUND at Position " << get<0>(deref) << " * " << get<1>(deref);
            exit(0);
        }
        else if(elem < arr[get<0>(deref)][get<1>(deref)])
            high = mid - 1;
        else
            low = mid + 1;        
    }
    cout << "\nNumber not in Matrix";
    
}