// Time Complexity:	O(Log N)
// Space Complexity:	O(1)
#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i =0;i<n;i++)
		cin >> arr[i];

	int num;
	cin >> num;

	int low = 0, high = n-1;
	int mid;

	while(low <= high){
		mid = (low+high)/2;
		if(arr[mid] == num){
			cout << "FOUND";
			break;
		}
		else if(num < arr[mid])
			high = mid - 1;
		else 
			low = mid + 1;

	}

	if(low > high)
		cout << "NOT FOUND";

	return 0;
}
