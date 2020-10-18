// Time Complexity :	O(N)
// Space Complexity:	O(N)

#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0;i<n;i++)
		cin >> arr[i];

	int low = 0, mid = 0, high = n-1;

	while(mid <= high){
		if(arr[mid] == 1){
			mid+=1;
		}
		else if(arr[mid] == 0){
			//Swap arr[mid] with arr[low]
			int temp = arr[mid];
			arr[mid] = arr[low];
			arr[low]= temp;
			mid+=1;
			low+=1;
		}
		else if(arr[mid] == 2){
			//Swap arr[mid] with arr[high]
			int temp = arr[mid];
			arr[mid] = arr[high];
			arr[high] = temp;
			high-=1;
		}
		else
			break;
	}

	for(int i =0;i<n;i++)
		cout << arr[i] << ",";
}
