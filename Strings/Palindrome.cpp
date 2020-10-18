// Time complexity:	O(N)
// Space Complexity:	O(1)
#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	getline(cin,s);
	int l = s.length();
	char a , b;
	int problem = 0;
	for(int i =0,j=l-1;i<l/2+1;i++,j--){
		a = s[i];
		b = s[j];
			if(a!=b){
				problem=1;
				break;
			}
	}

	if(problem)
		cout << "Not a palindrome" << endl;
	else
		cout << "Palindrome" << endl;
}
