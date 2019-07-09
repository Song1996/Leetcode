#include<stack>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans(seq.length(), 0);
        stack<int> mem;
        for(int i = 0; i < seq.length(); i++) {
            if(seq[i] == '(') {
                if(mem.empty()) mem.push(i);
                else {
                    ans[i] = 1 - ans[mem.top()];
                    mem.push(i);
                }
            } else if (seq[i] == ')') {
                ans[i] = ans[mem.top()];
                mem.pop();
            } else continue;
        }
        return ans;
    }
};