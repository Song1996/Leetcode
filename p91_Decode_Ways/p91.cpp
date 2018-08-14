#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s.length()==0) return 0;
        int t1 = s[s.length()-1]=='0'?0:1;
        int t2 = 1;
        int t;
        for(int i = s.length()-2; i>=0; i--) {
            if( int(s[i]) == int('0') ) {
                t2 = t1;
                t1 = 0;
            }else if(int(s[i]) == int('1')) {
                t = t1;
                t1 = t1 + t2;
                t2 = t;
            }else if(int(s[i])==int('2')&&int(s[i+1])<=int('6')&&int(s[i+1])>=int('0')) {
                t = t1;
                t1 = t1 + t2;
                t2 = t;
            }else{
                t2 = t1;
            }
        }
        return t1;
    }
};

int main () {
    string x = "10";
    Solution s;
    printf("%d\n",s.numDecodings(x));
	return 0;
}