#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
#define ERROR -1289333
stack<pair<int, int>> mystack;
void addElement(int x){
    int newmin = mystack.empty() ? x : min(mystack.top().second, x);
    mystack.push({x, newmin}); 
}
int popElement(){
    int res;
    if(!mystack.empty()){
        res = mystack.top().first;
        mystack.pop();
    }
    else
        res = ERROR;
    return res;
}
int minimumElement(){
    if(!mystack.empty())
        return mystack.top().second;
    return ERROR;
}
int main(){
    addElement(45);
    addElement(67);
    addElement(13);
    addElement(78);
    addElement(23);
    addElement(81);
    cout << minimumElement();
    return 0;
}

//https://cp-algorithms.com/data_structures/stack_queue_modification.html