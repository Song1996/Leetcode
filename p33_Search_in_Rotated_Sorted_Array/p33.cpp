#include<iostream>
#include<vector>
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
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        else if (nums.size()==1) return target == nums[0]?0:-1;
        else if (nums.size()==2) {
            if (nums[0]==target) return 0;
            if (nums[1]==target) return 1;
            return -1;
        }
        int min_pos = find_min_pos(nums.begin(), nums.size());
        VectorTools V;
        int p1 = V.binary_search(nums.begin(),min_pos,true,target);
        if(nums[p1]==target) return p1;
        int p2 = V.binary_search(nums.begin()+min_pos,nums.size()-min_pos,true,target);
        if(nums[p2+min_pos]==target) return p2+min_pos;
        return -1;
    }
    int find_min_pos(vector<int>::iterator first, int size) {
        if(size < 1)  return -1;
        if(size == 1) return 0;
        if(size == 2) return (*first)<(*(first+1))?0:1;
        int l = 0;
        int r = size - 1;
        if(*(first+l)<*(first+r)) return -1;
        int mid = (l+r)/2;
        while( (r-l)>1 ) {
            if(*(first+mid)<*(first+r)) r = mid;
            else if(*(first+mid)==*(first+r)) return -1;
            else l = mid;
            mid = (l+r)/2;
        }return r;
    }
};

int main () {
    vector<int> x;
    for(int i = 4; i < 8; i ++) {
        x.push_back(i);
    }
    for(int i = 0; i < 3; i ++) {
        x.push_back(i);
    }
    VectorTools V;
    V.vector_display(x);
    Solution s;
    printf("%d\n",s.search(x,4));
}