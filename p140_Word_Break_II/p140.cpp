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

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        map<string, int> d;
        int mlen = 0;
        for(int i = 0; i < wordDict.size(); i++) {
            d[wordDict[i]] = 0;
            if(wordDict[i].length() > mlen) mlen = wordDict[i].length();
        }
        vector<string> ans;
        if(s.length()==0) return ans;
        vector<string> mem;
        map<string, vector<string> > dict;
        ans = dfs(d, s, mlen, dict);
        return ans;
    }
    vector<string> dfs(map<string, int>& d, string s, int mlen, map<string, vector<string> >& dict) {
        if(dict.find(s) != dict.end()) return dict[s];
        vector<string> ans;
        if(s.length()==0) {
            dict[s] = ans;
            return ans;
        }
        if(d.find(s)!=d.end()) ans.push_back(s);
        for(int i = 1; i < s.length() && i<=mlen; i++) {
            string t = s.substr(0, i);
            if(d.find(t)!=d.end()) {
                vector<string> sub_ans = dfs(d, s.substr(i, s.length()-i), mlen, dict);
                for(int j = 0; j < sub_ans.size(); j++) ans.push_back(t+" "+sub_ans[j]);
            }
        }
        dict[s] = ans;
        return ans;
    }
};

int main () {
    string x = "pineapplepenapple";
    string xlist[] = {"apple", "pen", "applepen", "pine", "pineapple"};
    vector<string> w(xlist, xlist+sizeof(xlist)/sizeof(string));
    Solution s;
    vector<string> y = s.wordBreak(x, w);
    for(int i = 0; i < y.size(); i++) printf("%s\n",y[i].c_str());
	return 0;
}