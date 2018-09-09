#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
using namespace std;
#define size_of_alphabet 26

class Trie {
public:
    struct Trienode {
        struct Trienode* children[size_of_alphabet];
        bool is_end;
    };
    struct Trienode *genTrienode(void) {
        struct Trienode* pnode = new struct Trienode;
        memset(pnode->children, 0, sizeof(pnode->children));
        pnode->is_end = false;
        return pnode;
    }
    /** Initialize your data structure here. */
    struct Trienode* root;
    Trie() {
        root = genTrienode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        struct Trienode* p = root;
        for(int i = 0; i < word.length(); i++) {
            char c = word[i];
            if(!p->children[c-'a']) p->children[c-'a'] = genTrienode();
            p = p->children[c-'a'];
        }
        p->is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        struct Trienode* p = root;
        for(int i = 0; i < word.length(); i++) {
            char c = word[i];
            if(p->children[c-'a']) p = p->children[c-'a'];
            else return false;
        }
        return p->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        struct Trienode* p = root;
        for(int i = 0; i < prefix.length(); i++) {
            char c = prefix[i];
            if(p->children[c-'a']) p = p->children[c-'a'];
            else return false;
        }
        return true;
    }
};

int main() {
    Trie trie = *(new Trie());
    trie.insert("apple");
    printf("%s\n",trie.search("apple")?"true":"false");   // returns true
    printf("%s\n",trie.search("app")?"true":"false");     // returns false
    printf("%s\n",trie.startsWith("app")?"true":"false"); // returns true
    trie.insert("app");
    printf("%s\n",trie.search("app")?"true":"false"); // return true
    return 0;
}