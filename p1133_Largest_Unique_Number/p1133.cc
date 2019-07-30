#include <set>
#include <vector>
using namespace std;
class Solution {
    int cnt[1001];
    set<int> mem;
public:
    int largestUniqueNumber(vector<int>& A) {
        for(auto i:A) {
            cnt[i]++;
            if(cnt[i] == 1) {
                mem.insert(i);
            } else if(cnt[i] == 2){
                mem.erase(i);
            }
        }
        return mem.empty() ? -1 : *mem.rbegin();
    }
};