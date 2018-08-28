#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <assert.h>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
using namespace std;

class WordDictionary {
public:
    map<string, int> mem;
    /** Initialize your data structure here. */
    WordDictionary() {
        mem.clear();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        mem[word] = 1;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        for(map<string, int>::iterator it=mem.begin(); it!=mem.end(); it++) {
            if(match(it->first, word)) return true;
        }
        return false;
    }

    bool match(string s, string p) {
        if(s.length()!=p.length()) return false;
        for(int i = 0; i < s.length(); i++) {
            if(p[i]=='.') continue;
            if(s[i]!=p[i]) return false;
        }
        return true;
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

int main () {
    WordDictionary* obj = new WordDictionary();
    obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");
    printf("%s\n",obj->search("pad")?"true":"false");
    printf("%s\n",obj->search("bad")?"true":"false");
    printf("%s\n",obj->search(".ad")?"true":"false");
    printf("%s\n",obj->search("b..")?"true":"false");
	return 0;
}