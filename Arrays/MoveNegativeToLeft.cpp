// Time Complexity:	O(N)
// Space Complexity:	O(1)

//Two pointer Method

#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i =0;i<n;i++)
		cin >> arr[i];

	int low = 0, high = n-1;

	while(low <= high){
		if(arr[low] < 0 && arr[high] < 0)
			low+=1;
		else if(arr[low] >= 0 && arr[high] < 0){
			int temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
			low+=1;
			high-=1;
		}
		else if(arr[low] >= 0 && arr[high] >= 0)
			high-=1;
		else if(arr[low] < 0 && arr[high] >= 0){
			low+=1;
			high-=1;
		}
		else
			return 0;
	}

	for(int i =0;i<n;i++)
		cout << arr[i] << ",";
	return 0;
}
