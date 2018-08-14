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
    string getPermutation(int n, int k) {
        if(n<1||n>9) return string("");
        fac[0] = 1;
        for(int i = 1; i <= n ; i++) fac[i] = fac[i-1]*i;
        if(k<1||k>fac[n]) return string("");
        string ans(n,'x');
        for(int i = 0; i < n; i++) ans[i] = char(int('1')+i);
        //printf("%s\n",ans.c_str());
        k--;
        for(int pos = 0; pos < n; pos++){
            int tar = k/fac[n-pos-1];
            k -= tar*(fac[n-pos-1]);
            if(tar==0) continue;
            swap(ans[pos],ans[pos+tar]);
            sort(ans.begin()+pos+1,ans.end());
            //printf("%d, %s\n",k,(ans.substr(pos+1,n)).c_str());
        }
        return ans;
    }
    int fac[10];
};

int main () {
    Solution s;
    int n,k;
    n = 3, k = 3;
    printf("%s\n",s.getPermutation(n,k).c_str());
    n = 4, k = 9;
    printf("%s\n",s.getPermutation(n,k).c_str());
    n = 10, k = 9;
    printf("%s\n",s.getPermutation(n,k).c_str());
	return 0;
}