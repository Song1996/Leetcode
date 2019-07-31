#include<map>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> unappeared;
        unordered_map<int,int> mem;
        for(auto i:arr2) mem[i] = 0;
        for(auto i:arr1) {
            if(mem.find(i) == mem.end()) {
                if(unappeared.find(i) == unappeared.end()) unappeared[i] = 1;
                else unappeared[i]++;
            }
            else mem[i]++;
        }
        vector<int> ans;
        for(auto i:arr2){
            for(int j = 0; j < mem[i]; j++) {
                ans.push_back(i);
            }
        }
        for(auto i:ans) {
            printf("%d ", i);
        }
        printf("\n");
        for(auto i:unappeared) {
            printf("%d %d, ",i.first, i.second);
            for(int j = 0; j < i.second; j++) {
                ans.push_back(i.first);
            }
        }
        printf("\n");
        return ans;
    }
};