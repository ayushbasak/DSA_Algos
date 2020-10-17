//Time Complexity O(2N) =>	O(N)
//Space Complexity 		O(N) 

#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int arr[n];
	int count0=0,count1=0,count2=0;
	for(int i =0;i<n;i++){
		cin >> arr[i];
		if(arr[i] == 0)
			count0 += 1;
		else if(arr[i] == 1)
			count1 += 1;
		else if(arr[i] == 2)
			count2 += 1;
		else
			break;
	}
	for(int i = 0;i<n;i++){
		if(count0 > 0){
			arr[i] = 0;
			cout << arr[i] << ",";
			count0 -=1;
		}
		else if(count1 > 0){
			arr[i] = 1;
			cout << arr[i] << ",";
			count1 -=1;
		}
		else if(count2 > 0){
			arr[i] = 2;
			cout << arr[i] << ",";
			count2 -=1;
		}
		else
			break;
	}
}
