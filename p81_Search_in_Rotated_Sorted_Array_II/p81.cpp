#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(vector<int>:: iterator it = nums.begin(); it != nums.end(); it++ ){
            if(*it==target) return true;
        }
        return false;
    }
};

int main () {
    vector<int> x;
    for(int i = 4; i < 8; i ++) {
        x.push_back(0);
    }
    x.push_back(1);
    for(int i = 0; i < 3; i ++) {
        x.push_back(0);
    }
    Solution s;
    printf("%d\n",s.search(x,1));
}