#include <iostream>
#include <string>
using namespace std;


int main(){
	string x, y;
	cin >> x >> y;
	int len1 = x.length(), len2 = y.length();

	int dp[1001][1001];

	//Initialization
	for(int i =0; i<1001;i++)
		for(int j=0; j<1001;j++)
			if(!i or !j)
				dp[i][j] = 0;

	int maxResult = 0;
	for(int i=1; i<=len1; i++){
		for(int j =1; j<=len2; j++){
			if(x[i -1] == y[j - 1]){
				dp[i][j] = 1 + dp[i-1][j-1];
				maxResult = max(maxResult, dp[i][j]);
			}
			else{
				dp[i][j] = 0;
			}
		}
	}
	cout << maxResult << endl;
	return 0;
}