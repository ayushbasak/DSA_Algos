// https://www.youtube.com/watch?v=g_hIx4yn9zg&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=20


#include <iostream>
#include <string>
using namespace std;

int dp[1001][1001];

int LFS(string x, string y, int pos1, int pos2){
	if(pos1 == 0 || pos2 == 0)
		return 0;

	if(x[pos1 - 1] == y[pos2 - 1])
		return 1 + LFS(x, y, pos1 -1, pos2 -1);
	else{
		int c1 = LFS(x, y, pos1, pos2 - 1);
		int c2 = LFS(x, y, pos1 - 1, pos2);

		return max(c1, c2);
	}
}
int main(){
	string x = "jigiuajsldlisdfouihgaudfaf";
	string y = "klasdugfajdbfuyasdfuvbajkasu";

	cout << LFS(x, y, x.length(), y.length());
	return 0;
}