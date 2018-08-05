#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p = 0;
        for (int i = 0;  i < nums.size(); i ++) {
            if (nums[i] != nums[p]) nums[++p] = nums[i];
        }
        return min(++p, (int)nums.size());
    }
};

int main() {
    Solution s;
    int intList1[] = {1,1,2};
    vector<int> v1(intList1,intList1+sizeof(intList1)/sizeof(int));
    printf("%d\n",s.removeDuplicates(v1));
    for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++){
        printf("%d ",*it);
    }printf("\n");

    int intList2[] = {0,0,1,1,1,2,2,3,3,4};
    vector<int> v2(intList2,intList2+sizeof(intList2)/sizeof(int));
    printf("%d\n",s.removeDuplicates(v2));
    for(vector<int>::iterator it = v2.begin(); it != v2.end(); it++){
        printf("%d ",*it);
    }printf("\n");
}