#include <iostream>
#include <vector>
#include <map>
using namespace std;

class VectorTools{
public:
    void sorted(vector<int>::iterator first, vector<int>::iterator last) {
        if (first == last || first + 1 == last) return;
        vector<int>::iterator pivot = first;
        int temp;
        for (vector<int>::iterator it = first+1; it != last; it ++) {
            if (*it<*pivot) {
                temp = *it;
                *it = *(pivot+1);
                *(pivot+1) = *pivot;
                *pivot = temp;
                pivot ++;
            }
        }
        sorted(first, pivot);
        sorted(pivot+1, last);
    }

    int binary_search(vector<int>::iterator first, int size, bool have_sorted, int tar) {
        int l = 0;
        int r = size - 1;
        int mid = (l+r)/2;
        if (size==0) return -1;
        else if (size==1) return 0;
        if (!have_sorted) sorted(first, first+size);
        if (*(first+l)>=tar) return l;
        if (*(first+r)<=tar) return r;
        while (l < r - 1) {
            mid = (l+r)/2;
            if (*(first+mid) < tar) l = mid;
            else if (*(first+mid) == tar) {
                int i = 0;
                while((mid - i)>=0 && *(first+mid-i) ==  tar) i ++;
                return *(first+mid-i)==tar?(mid-i):(mid-i+1);
            }
            else r = mid; 
        }
        return (tar-*(first+l) >= *(first+r) - tar)?r:l;
    }

    void vector_display(vector<int>& v) {
        for (vector<int>:: iterator it = v.begin(); it != v.end(); it ++) {
            printf("%d ",*it);
        }printf("\n");
    }
};

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result,temp_result, distance;
        distance = INT_MAX;
        if (nums.size()<3) return result;
        VectorTools V;
        V.sorted(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; i ++) {
            if(i>0 && nums[i]==nums[i-1]) continue;
            for (int j = i+1; j < nums.size()-1; j ++) {
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                int l,r;
                l = nums[i];
                r = nums[j];
                int tar = target - (l + r);
                temp_result = nums[j+1+V.binary_search(nums.begin()+j+1,nums.size()-j-1,true,tar)];
                //printf("%d: %d %d %d\n",tar,l,r,temp_result);
                temp_result += (l+r);
                if(abs(temp_result-target)<distance){
                    result = temp_result;
                    distance = abs(temp_result-target);
                }
            }
        }
        return result;
    }
};

int main () {
    int intList[] = {-1, 0, 1, 1, 55};
    vector<int> v(intList, intList + sizeof(intList)/sizeof(int));
    Solution s;
    VectorTools V;
    int result = s.threeSumClosest(v,3);
    printf("%d\n",result);
}
