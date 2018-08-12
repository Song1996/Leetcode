#include <iostream>
#include <vector>
using namespace std;

class better_Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return vector<int>({-1,-1});
        
        vector<int> ans(2,-1);
        // first search for left range
        int left = 0, right = nums.size()-1;
        while (left +1 < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] >= target) right = mid;
            else left = mid;
        }
        if (nums[right] == target) ans[0] = right;
        if (nums[left] == target) ans[0] = left;
        
        // next search for right range
        left = 0; right = nums.size()-1;
        while (left +1 < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] <= target) left = mid;
            else right = mid;
        }
        if (nums[left] == target) ans[1] = left;
        if (nums[right] == target) ans[1] = right;
        return ans;
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> result = binaryRangeSearch(nums, 0, nums.size()-1, target);
        return result;
    }
private:
    vector<int> binaryRangeSearch(vector<int>& v, int first, int last, int target) {
        //printf("search: %d %d\n",first, last);
        vector<int> result(2, -1);
        int l = first;
        int r = last;
        if (r<l) { 
            return result;
        }else if (r==l && v[l] == target) {
            result[0] = l;
            result[1] = r;
            return result;
        }else if (r==l && v[l] != target) {
            return result;
        }else if (r==(l+1) && v[l]==target && v[r]==target) {
            result[0] = l;
            result[1] = r;
            return result;
        }else if (r==(l+1) && v[l]==target && v[r]!=target) {
            result[0] = l;
            result[1] = l;
            return result;
        }else if (r==(l+1) && v[l]!=target && v[r]==target) {
            result[0] = r;
            result[1] = r;
            return result;
        }else if (r==(l+1) && v[l]!=target && v[r]!=target) {
            return result;
        }else if (v[l]>target || v[r] < target){
            return result;
        }else if (v[l]==target && v[r]==target){
            result[0] = l;
            result[1] = r;
            return result;
        }else if (v[l]==target){
            result[0] = l;
            int mid = (l+r)/2;
            if (v[mid] == target) {
                result[1] = binaryRangeSearch(v, mid, r, target)[1];
                return result;
            } else if(v[mid] < target) {
                printf("error\n");
                return result;
            } else {
                result[1] = binaryRangeSearch(v, l, mid, target)[1];
                return result;
            }
        }else if (v[r]==target) {
            result[1] = r;
            int mid = (l+r)/2;
            if (v[mid] == target) {
                result[0] = binaryRangeSearch(v, l, mid, target)[0];
                return result;
            } else if(v[mid] > target) {
                printf("error\n");
                return result;
            } else {
                result[0] = binaryRangeSearch(v, mid, r, target)[0];
                return result;
            }            
        }else {
            int mid = (l+r)/2;
            if (v[mid] == target) {
                result[0] = binaryRangeSearch(v, l, mid, target)[0];
                result[1] = binaryRangeSearch(v, mid, r, target)[1];
                return result;
            }else if (v[mid] < target) {
                return binaryRangeSearch(v, mid, r, target);
            }else {
                return binaryRangeSearch(v, l, mid, target);
            }
        }
    }
};

int main () {
    vector<int> x;
    vector<int> y;
    Solution s;
    int target;
    x.push_back(5);
    x.push_back(7);
    x.push_back(7);
    x.push_back(8);
    x.push_back(8);
    x.push_back(10);
    target = 8;
    y = s.searchRange(x,target);
    for (vector<int>::iterator it = y.begin(); it != y.end(); it ++) {
        printf("%d ",*it);
    }printf("\n");
    target = 6;
    y = s.searchRange(x,target);
    for (vector<int>::iterator it = y.begin(); it != y.end(); it ++) {
        printf("%d ",*it);
    }printf("\n");    
}