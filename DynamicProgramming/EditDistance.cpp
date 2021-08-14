#include <iostream>
#include <string>
using namespace std;
int main(){
	string s1, s2;
	cin >> s1 >> s2;

	int l1 = s1.length(), l2 = s2.length();
	int dp[l1 + 1][l2 + 1];

	for(int i =0; i<= l1; i++)
		dp[i][0] = i;
	for(int j =0; j<= l2; j++)
		dp[0][j] = j;

	for(int i = 1; i<= l1; i++){
		for(int j = 1; j<= l2; j++){
			if(s1[i -1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else{
				int c1 = dp[i][j - 1]; // insert
				int c2 = dp[i - 1][j]; // delete
				int c3 = dp[i - 1][j - 1]; // repalce

				dp[i][j] = min(c1, min(c2, c3)) + 1;
			}
		}
	}

	cout << dp[l1][l2];
	return 0;
}