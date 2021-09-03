#include <iostream>
using namespace std;
class TrieNode {
public:
    bool isEnd;
    TrieNode * next[26];
    TrieNode();
    void insert(string s);
    void deleteWord(string s);
    bool search(string s);
};

TrieNode::TrieNode() {
    bool isEnd = false;
    for (int i = 0; i < 26; i++) {
        next[i] = NULL;
    }
}

void TrieNode::insert(string s) {
    int i = 0;
    TrieNode * p = this;
    while (i < s.length()) {
        if (p->next[s[i] - 'a'] == NULL) {
            p->next[s[i] - 'a'] = new TrieNode();
        }
        p = p->next[s[i] - 'a'];
        i++;
    }
    p->isEnd = true;
}

void TrieNode::deleteWord(string s) {
    int i = 0;
    TrieNode * p = this;
    while (i < s.length()) {
        if (p->next[s[i] - 'a'] == NULL) {
            return;
        }
        p = p->next[s[i] - 'a'];
        i++;
    }
    p->isEnd = false;
}

bool TrieNode::search(string s) {
    int i = 0;
    TrieNode * p = this;
    while (i < s.length()) {
        if (p->next[s[i] - 'a'] == NULL) {
            return false;
        }
        p = p->next[s[i] - 'a'];
        i++;
    }
    return p->isEnd;
}

int main() {
    TrieNode * root = new TrieNode();
    root->insert("ab");
    root->insert("abc");
    root->insert("abcd");
    root->insert("abcde");
    root->insert("abcdef");
    root->insert("abcdefg");
    cout << root->search("abcdefg") << endl;
    root->deleteWord("abcdefg");
    cout << root->search("abcdefg") << endl;
    return 0;
}
