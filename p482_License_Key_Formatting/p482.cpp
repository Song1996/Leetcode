#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int p = 0;
        for(int i = 0; i < S.length(); i++) {
            if(S[i]!='-') {
                S[p] = S[i];
                if(S[p]<='z'&&S[p]>='a') S[p] += 'A' - 'a';
                p++;
            }
        }
        S = S.substr(0,p);
        int m = S.length()%K;
        string ans = S.substr(0,m);
        for(int i = m; i < S.length(); i += K) {
            if(ans.length()==0) ans += S.substr(i,K);
            else ans += "-" + S.substr(i,K);
        }
        return ans;
    }
};

int main() {
    return 0;
}