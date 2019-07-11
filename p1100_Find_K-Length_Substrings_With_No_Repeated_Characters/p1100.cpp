#include <string>
using namespace std;

class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        if(S.length() == 0 || K > S.length() || K > 26) return 0;
        int ans = 0;
        int flag = 0;
        charFlag[0] = 1;
        for(int i = 1; i < 26; i++) charFlag[i] = charFlag[i-1] << 1;
        memset(charCount, 0, sizeof(charCount));
        for(int i = 0; i < K; i++) {
            int c = S[i] - 'a';
            charCount[c]++;
            if(charCount[c] == 2)
                flag = flag ^ charFlag[c];
        }
        if(!flag) ans++;
        for(int i = K; i < S.length(); i++) {
            int c1 = S[i] - 'a';
            int c2 = S[i-K] - 'a';
            charCount[c1]++;
            charCount[c2]--;
            if(c1!=c2) {
                if(charCount[c1] == 2)
                    flag = flag ^ charFlag[c1];
                if(charCount[c2] == 1)
                    flag = flag ^ charFlag[c2];
            }
            if(!flag) ans++;
        }
        return ans;
    }
private:
    int charFlag[26];
    int charCount[26];
};