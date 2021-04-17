#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int startTime[] = {1,3,0,5,8,5};
    int endTime[] = {2,4,6,7,9,9};
    int size = sizeof(startTime)/sizeof(startTime[0]);
    pair<int ,int> pairedTime[size];
    for(int i=0;i<size;i++){
        pairedTime[i].first = endTime[i];
        pairedTime[i].second = startTime[i];
    }

    //Sort according to end Times;
    sort(pairedTime, pairedTime + size);
    int count = 1;
    int j =0;
    for(int i =1;i<size;i++){
        if(pairedTime[i].second >= pairedTime[i].first){
            ++count;
            j = i;
        }
    }
    cout << count;
    return 0;
}