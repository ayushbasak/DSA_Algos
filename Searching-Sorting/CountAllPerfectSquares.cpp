// Time Complexity :    O(1)
// Space Complexity :   O(1) 
/*
Idea => For a given number X > 1, 
it will have at least one square root.
64  => 1,4,9,16,25,36,49,64 compiled as 
8   => 1,2,3,4 ,5, 6, 7, 8
*/
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin >> n;
    cout << floor(sqrt(n));
    return 0;
}