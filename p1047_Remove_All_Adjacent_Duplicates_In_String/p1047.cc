#include<vector>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> mem;
        for(int i = 0; i < S.length(); i++) {
            if(mem.empty()) mem.push(S[i]);
            else if(mem.top() == S[i]){
                while(!mem.empty() && mem.top() == S[i]) {
                    mem.pop();
                }
            } else mem.push(S[i]);
        }
        stack<char> mem1;
        while(!mem.empty()) {
            mem1.push(mem.top());
            mem.pop();
        }
        string ans("");
        while(!mem1.empty()) {
            ans.push_back(mem1.top());
            mem1.pop();
        }
        return ans;
    }
};