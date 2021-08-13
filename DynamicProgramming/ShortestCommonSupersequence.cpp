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


	//Printing
	int i = len1, j = len2;
	string temp = "";
	while(i >=0 and j >= 0){
		if(x[i - 1] == y[j - 1]){
			temp = x[i-1] + temp;
			i--; j--;
		}
		else{
			if(dp[i-1][j] >= dp[i][j-1]){
				temp = x[i-1] + temp;
				i--;

			}
			else{
				temp = y[j-1] + temp;
				j--;
			}
		}
	}
    
    while(i > 0){
        temp  = x[i-1] + temp;
        i--;
    }
    while(j > 0){
        temp = y[j-1] + temp;
        j--;
    }

	int shortestCommonSupersequenceLength = len1 + len2 - dp[len1][len2];
	cout << shortestCommonSupersequenceLength << endl;
	cout << temp << endl;
	return 0;
}