#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = -1;
        for(int i = 0; i < nums.size()-1; i++) if(nums[i]<nums[i+1]) k = i;
        if(k==-1) {
            reverse(nums.begin(), nums.end()); 
            return;
        }
        int l = k+1;
        for(int i = k+2; i < nums.size(); i++) if(nums[k]<nums[i]) l = i;
        swap(nums[k], nums[l]);
        reverse(nums.begin()+k+1, nums.end());
        return;
    }
};

int main() {
    return 0;
}