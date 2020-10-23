// Time Complexity:	O(N^2)
// Space Complexity:	O(N^2)
#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i =0;i<n;i++)
		cin >> arr[i];

	for(int i =0;i<n-1;i++){
		int arr_min_index = i;
		for(int j = i+1;j<n;j++){
			if(arr[j] < arr[arr_min_index])
				arr_min_index = j;
		}
		int temp = arr[arr_min_index];
		arr[arr_min_index] = arr[i];
		arr[i] = temp;
	}

	for(int i =0;i<n;i++)
		cout << arr[i] << " , ";
}
