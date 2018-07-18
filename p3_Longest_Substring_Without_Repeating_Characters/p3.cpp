#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sl = s.size();
        int p1 = 0;
        int p2 = 0;
        int l = 0;
        int maxl = 0;
        int hashmap[256];
        memset(hashmap, 0, sizeof(hashmap));
        while(p1 < sl){
            while(p2 < sl){
                if(hashmap[(unsigned int) s[p2]] == 0){
                    hashmap[(unsigned int) s[p2]] = 1;
                    l++;
                    if(l > maxl) maxl = l;
                }else break;
                p2++;
            }
            hashmap[(unsigned int) s[p1]] = 0;
            p1++;
            l--;
        }
        return maxl;
    }
};

int main(){
    Solution s;
    string ss;
    while(cin>>ss){
        //cout<<ss.size()<<endl;
        cout<<s.lengthOfLongestSubstring(ss)<<endl;
    }
}