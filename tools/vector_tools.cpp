#include <iostream>
#include <vector>
using namespace std;

class VectorTools{
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        if(nums.size()==0) return ans;
        int l = 0;
        int r = nums.size() - 1;
        if (nums[l] > target || nums[r] < target) return ans;
        int mid;
        while((r-1)>l) {    
            mid = l + (r-l)/2;       
            if(nums[mid] >= target) r = mid;
            else l = mid;
        }
        if(nums[r]==target) ans[0] = r;
        if(nums[l]==target) ans[0] = l;
        l = 0;
        r = nums.size()-1;
        while((r-1)>l) {
            mid = l + (r-l)/2;
            if(nums[mid] <= target) l = mid;
            else r = mid;
        }
        if(nums[l] == target) ans[1] = l;
        if(nums[r] == target) ans[1] = r;
        return ans;
    }
    
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
int main () {
    vector<int> v;
    v.push_back(1);
    v.push_back(55);
    VectorTools s;
    s.sorted(v.begin(), v.end());
    s.vector_display(v);
    printf("%d\n",s.binary_search(v.begin(),v.size(),true, 2));
}