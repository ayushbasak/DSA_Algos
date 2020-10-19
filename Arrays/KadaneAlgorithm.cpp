// Time Complexity:	O(N)
// Space Complexity:	O(1)
#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i =0;i<n;i++)
		cin >> arr[i];

	int local_max = 0;
	int global_max = 0;

	for(int i =0;i<n;i++){
		local_max = max(arr[i], arr[i] + local_max);
		global_max = max(local_max, global_max);
	}

	cout << "Max SubArray Sum:\t" << global_max;
}
