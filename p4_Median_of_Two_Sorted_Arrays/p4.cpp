#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    double findKSortedArrays(vector<int>& nums1, vector<int>& nums2,int k, bool flag){
        /*for(vector<int>::iterator i = nums1.begin(); i != nums1.end(); i++) printf("%d ",*i); printf("\n");
        for(vector<int>::iterator i = nums2.begin(); i != nums2.end(); i++) printf("%d ",*i); printf("\n");
        printf("%d\n\n",k);*/
        if(nums1.size()==0){
            return flag?(nums2[k-1]+nums2[k])/2.0:nums2[k-1];
        }
        if(nums2.size()==0){
            return flag?(nums1[k-1]+nums1[k])/2.0:nums1[k-1];
        }
        if(k==1){
            return flag?(min(nums1[0],nums2[0])+findKSortedArrays(nums1,nums2,2,false))/2:min(nums1[0],nums2[0]);
        }

        if(nums1.size() < k/2){
            if(nums2[k/2-1] < nums1[nums1.size()-1]){
                nums2.erase(nums2.begin(), nums2.begin()+(k/2));
                return findKSortedArrays(nums1, nums2, k - (k/2),flag);
            }else{
                return flag?(nums2[k - nums1.size()-1]+nums2[k - nums1.size()])/2.0:nums2[k - nums1.size()-1];
            }
        }else if(nums2.size() < k/2){
            if(nums1[k/2-1]<nums2[nums2.size()-1]){
                nums1.erase(nums1.begin(), nums1.begin()+(k/2));
                return findKSortedArrays(nums1, nums2, k-(k/2), flag);
            }else{
                return flag?(nums1[k - nums2.size()-1]+nums1[k - nums2.size()])/2.0:nums1[k - nums2.size()-1];
            }
        }else{
            if(nums1[k/2-1]==nums2[k/2-1]){
                if(k%2==0){
                    return flag?(min(nums1[k/2],nums2[k/2])+nums1[k/2-1])/2.0:nums1[k/2-1];
                }else{
                    return flag?(min(nums1[k/2],nums2[k/2])+findKSortedArrays(nums1,nums2,k+1,false))/2:min(nums1[k/2],nums2[k/2]);
                }
            }else if(nums1[k/2-1]<nums2[k/2-1]){
                nums1.erase(nums1.begin(), nums1.begin() + (k/2));
                return findKSortedArrays(nums1, nums2, k - (k/2),flag);
            }else{
                nums2.erase(nums2.begin(), nums2.begin() + k/2);
                return findKSortedArrays(nums1, nums2, k - (k/2),flag);
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int len = len1 + len2;
        /*printf("len of nums1: %4d\nlen of nums2: %4d\n", len1, len2);
        printf("nums1: "); 
        for(int i = 0; i < len1; i++) printf("%d ",nums1[i]);
        printf("\nnums2: "); 
        for(int i = 0; i < len2; i++) printf("%d ",nums2[i]);
        printf("\n");*/
        if(len%2==1){
            return findKSortedArrays(nums1,nums2,len/2+1,false);
        }else{
            return findKSortedArrays(nums1,nums2,len/2,true);
        }
    }
};

int main(){
    vector<int> nums1;
    for(int i = 13; i < 23; i++){
        nums1.push_back(i);
    }
    vector<int> nums2;
    for(int i = 31; i < 51; i++){
        nums2.push_back(i);
    }
    Solution s;
    printf("answer %f\n",s.findMedianSortedArrays(nums1, nums2));
    return 0;
}