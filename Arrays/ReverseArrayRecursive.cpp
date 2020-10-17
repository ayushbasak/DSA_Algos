#include <iostream>
using namespace std;
void Reverse(int * array,int start, int end){
	if (start >= end)
		return;
	int temp = array[start];
	array[start] = array[end];
	array[end] = temp;

	Reverse(array,start+1,end-1);
}
int main(){
	int n;
	cin >> n;

	int arr[n];
	for(int i = 0;i<n;i++)
		cin >> arr[i];

	Reverse(arr,0,n-1);

	for(int i =0;i<n;i++)
		cout << arr[i] << endl;
}
