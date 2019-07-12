#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        map< int, vector<int> > mem;
        vector<int> key2rm;
        for(int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            nums[i] = nums.size();
            if(mem.find(n) == mem.end()) mem[n] = vector<int>();
            mem[n].push_back(i);
            key2rm.clear();
            for(auto it = mem.rbegin(); it != mem.rend(); it++) {
                if(it->first > n) {
                    for(int j = 0; j < (it->second).size(); j++) {
                        nums[(it->second)[j]] = i;
                    }
                    key2rm.push_back(it->first);
                }
            }
            for(int j = 0; j < key2rm.size(); j++) {
                mem.erase(key2rm[j]);
            }
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            ans += nums[i] - i;
        }
        return ans;
    }
};