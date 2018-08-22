#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <assert.h>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        map<int,int> d;
        int h;
        int bithelper = 0x000fffff;
        for(int i = 0; i < 10; i++) {
            h<<=2;
            if(s[i]=='A') h^=0x00000001;
            else if(s[i]=='C') h^=0x00000002;
            else if(s[i]=='G') h^=0x00000003;
        }
        d[h&bithelper] = 1;
        for(int i = 10; i < s.length(); i++) {
            h<<=2;
            if(s[i]=='A') h^=0x00000001;
            else if(s[i]=='C') h^=0x00000002;
            else if(s[i]=='G') h^=0x00000003;
            if(d.find(h&bithelper)!=d.end()) {
                if((d[h&bithelper]++)==1)ans.push_back(s.substr(i-9,10));
            }else d[h&bithelper] = 1;
        }
        return ans;
    }
};

int main () {
    string x = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    Solution s;
    vector<string> y = s.findRepeatedDnaSequences(x);
    for(int i = 0; i < y.size(); i++) printf("%s\n",y[i].c_str());
	return 0;
}