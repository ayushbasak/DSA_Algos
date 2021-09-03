#include <iostream>
#include <vector>
using namespace std;
class TrieNode {
public:
    bool isEnd;
    int freq;
    TrieNode * next[26];
    TrieNode();
    void insert(string s);
};

TrieNode::TrieNode() {
    bool isEnd = false;
    freq = 0;
    for (int i = 0; i < 26; i++) {
        next[i] = NULL;
    }
}

void TrieNode::insert(string s) {
    int i = 0;
    TrieNode * p = this;
    while (i < s.length()) {
        p->freq += 1;
        if (p->next[s[i] - 'a'] == NULL) {
            p->next[s[i] - 'a'] = new TrieNode();
        }
        p = p->next[s[i] - 'a'];
        i++;
    }
    p->isEnd = true;
}

string findPrefix(TrieNode * head, string s){

    int n = s.length();
    string res = "";
    TrieNode * ptr = head;
    int i = 0;
    ptr = ptr->next[s[i] - 'a'];

    res += s[i];

    for(i = 1; i< n; i++){
        if(ptr->freq == 1)
            return res;
        ptr = ptr->next[s[i] - 'a'];
        res += s[i];
    }

    return res;
}

int main(){
    vector<string> t = {"zebra", "dog", "dove", "duck"};
    TrieNode head = TrieNode();
    for(string s: t){
        head.insert(s);
    }

    vector<string> res;
    for(int i =0; i< t.size(); i++){
        cout << t[i] << " : " << findPrefix(&head, t[i]) << endl;
    }
    return 0;
}