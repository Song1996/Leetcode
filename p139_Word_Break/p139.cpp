#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.length()<1) return false;
        int* mem = new int[s.length()+1];
        for(int i = 0; i <= s.length(); i++) mem[i] = 0;
        //memset(mem, 0, sizeof(mem));
        map<string, int> d;
        for(int i = 0; i<wordDict.size(); i++) {
            d[wordDict[i]] = 1;
        }
        /*for(map<string, int>::iterator it=d.begin(); it!=d.end(); it++){
            printf("%s\n",it->first.c_str());
        }*/
        mem[s.length()] = 1;
        for(int i = s.length()-1; i>=0; i--) {
            for(int j = 1; i+j <= s.length(); j++) {
                if(mem[i+j]==1 && d.find(s.substr(i,j))!=d.end()){
                    mem[i] = 1;
                }
            }
        }
        //for(int i = 0; i <= s.length(); i++) printf("%d ",mem[i]);
        //printf("\n");
        return mem[0];
    }
};

int main () {
    Solution s;
    string x = "leetcode";
    vector<string> d; d.push_back("leet"); d.push_back("code");
    printf("%s\n",s.wordBreak(x,d)?"true":"false");
    x = "applepenapple";
    d.clear(); d.push_back("apple"); d.push_back("pen");
    printf("%s\n",s.wordBreak(x,d)?"true":"false");
    x = "catsandog";
    d.clear(); d.push_back("cats"); d.push_back("dog");
    d.push_back("sang"); d.push_back("and"); d.push_back("cat");
    printf("%s\n",s.wordBreak(x,d)?"true":"false");
	return 0;
}