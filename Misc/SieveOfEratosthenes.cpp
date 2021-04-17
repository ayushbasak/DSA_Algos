#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    bool arr[n];
    arr[0] = false;
    arr[1] = false;
    for(int i = 2;i<n-1;i++)
        arr[i] = true;
    
    for(int i =2; i<n-1;i++){
        for(int j = i*i; j< n-1;j+=i)
            arr[j] = false;
    }
    int count = 0;
    for(int i =0;i<n-1;i++){
        if(arr[i]){
            cout << i << "\n";
            ++count;
        }
    }
    
    cout << "\nTotal Primes between 1 and " << n << " : " << count;
    return 0;
}