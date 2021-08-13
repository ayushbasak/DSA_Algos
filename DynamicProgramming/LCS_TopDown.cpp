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

	for(int i=1; i<=len1; i++){
		for(int j =1; j<=len2; j++){
			if(x[i -1] == y[j - 1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else{
				int c1 = dp[i-1][j];
				int c2 = dp[i][j-1];

				dp[i][j] = max(c1, c2);
			}
		}
	}

	cout << dp[len1][len2] << endl;

	return 0;
}