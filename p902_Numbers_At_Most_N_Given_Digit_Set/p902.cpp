#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
using namespace std;
class Solution {
public:
    map<int, int> fdict;
    map<int, int> tdict;
    int atMostNGivenDigitSet(vector<string>& D, int N, bool lock = false) {
        fdict.clear(); tdict.clear();
        return helper(D,N,false);
    }
    int helper(vector<string>& D, int N, bool lock = false) {
        if(N==0) return 0;
        if(lock && tdict.find(N)!=tdict.end()) return tdict[N];
        if(!lock && fdict.find(N)!=fdict.end()) return fdict[N];
        //printf("%d %s\n",N,lock?"true":"false");
        int ans = 0;
        int b = 1;
        int l = 1;
        int p = 1;
        while(N >= b*10) {
            b *= 10;
            l++;
            p *= D.size();
        }
        int top = N/b;
        bool flag = false;
        for(int i = 0; i < D.size(); i++) {
            if( D[i][0]-'0' < top) ans++;
            else if(D[i][0]-'0' == top) flag = true;
        }
        if(ans>0) ans *= p;//int(pow(D.size(), l-1));
        ans += lock?0:helper(D, b-1, false);
        ans = flag&&(N-top*b)>=(b/10)?ans+helper(D, N-top*b,true):ans;
        if(flag && N-top*b==0 && l==1) ans++;
        if(lock) tdict[N] = ans;
        else fdict[N] = ans;
        return ans;
    }    
};


int main() {
    Solution s;
    /*string s1[] = {"1","3","5","7"};
    vector<string> D1(s1, s1+4);
    int N1 = 100;
    //s.tdict.clear();
    //s.fdict.clear();
    printf("%d\n",s.atMostNGivenDigitSet(D1, N1));
    for(map<int,int>::iterator it = s.tdict.begin(); it!=s.tdict.end(); it++) printf("true %d %d\n",it->first, it->second);
    for(map<int,int>::iterator it = s.fdict.begin(); it!=s.fdict.end(); it++) printf("false %d %d\n",it->first, it->second);
    string s2[] = {"1","4","9"};
    vector<string> D2(s2, s2+3);
    int N2 = 1000000000;
    //s.tdict.clear();
    //s.fdict.clear();
    printf("%d\n",s.atMostNGivenDigitSet(D2, N2));
    for(map<int,int>::iterator it = s.tdict.begin(); it!=s.tdict.end(); it++) printf("true %d %d\n",it->first, it->second);
    for(map<int,int>::iterator it = s.fdict.begin(); it!=s.fdict.end(); it++) printf("false %d %d\n",it->first, it->second);*/
    string s3[] = {"1","5","7","8"};
    vector<string> D3(s3, s3+4);
    int N3 = 10212;
    //s.tdict.clear();
    //s.fdict.clear();
    printf("%d\n",s.atMostNGivenDigitSet(D3, N3));
    for(map<int,int>::iterator it = s.tdict.begin(); it!=s.tdict.end(); it++) printf("true %d %d\n",it->first, it->second);
    for(map<int,int>::iterator it = s.fdict.begin(); it!=s.fdict.end(); it++) printf("false %d %d\n",it->first, it->second);
    return 0;
}