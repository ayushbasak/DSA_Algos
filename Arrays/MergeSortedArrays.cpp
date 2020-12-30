// Time Complexity :    O(N)
// Space Complexity :   O(N)
#include <iostream>
using namespace std;
int main(){
    int n1, n2;
    cin >> n1 >> n2;
    int arr1[n1];
    int arr2[n2];
    for(int i =0;i<n1;i++)
        cin >> arr1[i];
    for(int i =0;i<n2;i++)
        cin >> arr2[i];


    int arr[n1+n2];
    int p1 = 0, p2 =0;
    int curr =0;
    while(curr != n1+n2){
        if(arr1[p1] <= arr2[p2]){
            arr[curr] = arr1[p1];
            if(p1 < n1)
                p1+=1;
        }
        else{
            arr[curr] = arr2[p2];
            if(p2 < n2)
                p2+=1;
        }
        curr+=1;
    }

    for(int i =0;i<n1+n2;i++){
        cout << arr[i] <<" ";
    }
}