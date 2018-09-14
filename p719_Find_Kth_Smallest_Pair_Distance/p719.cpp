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
    int smallestDistancePair(vector<int>& nums, int k) {
        const int BUCKET_SIZE = 1000000;
        vector<int> Bucket(BUCKET_SIZE,0);
        for(int i = 0; i < nums.size()-1; i++) {
            for(int j = i+1; j < nums.size(); j++) {
                Bucket[abs(nums[i]-nums[j])]++;
            }
        }
        k--;
        int ans = 0;
        while(k>0) {
            while(Bucket[ans]==0) ans++;
            if(k>=Bucket[ans]) {
                k -= Bucket[ans];
                ans++;
            }
            else return ans;
        }
        while(Bucket[ans]==0) ans++;
        return ans;
    }
};

int main() {
    int x[] = {32,100,4};
    vector<int> v(x,x+3);
    Solution s;
    printf("%d\n",s.smallestDistancePair(v,3));
    return 0;
}