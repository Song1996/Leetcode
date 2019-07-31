#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int ans = 0, score = 0;
        unordered_map<int, int> mem;
        for(int i = 0; i < hours.size(); i++) {
            score += hours[i] > 8 ? 1 : -1;
            if(score > 0) {
                ans = i + 1;
            } else {
                if(mem.find(score) == mem.end()) {
                    mem[score] = i;
                }
                if(mem.find(score-1) != mem.end()) {
                    ans = max(ans, i - mem[score-1]);
                }
            }
        }
        return ans;
    }
};