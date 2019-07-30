#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        queue<int> mem;
        int i = 0;
        for(; i < arr.size() - mem.size(); i++) {
            mem.push(arr[i]);
            if(!arr[i]) mem.push(0);
            arr[i] = mem.front();
            mem.pop();
        }
        while(i < arr.size()) {
            arr[i++] = mem.front();
            mem.pop();
        }
        return;
    }
};