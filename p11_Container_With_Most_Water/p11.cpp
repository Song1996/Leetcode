#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int maxsize = 0;
        int nowsize = 0;
        while (l<r) {
            nowsize = (r-l)*min(height[l],height[r]);
            if (nowsize > maxsize) maxsize = nowsize;
            if (height[l] < height[r]) l ++;
            else r --;
        }
        return maxsize;
    }
};

int main() {
    int x[] = {1,8,6,2,5,4,8,3,7};
    vector<int> v (x, x + sizeof(x)/sizeof(int));
    int y = 49;
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        printf("%d ",*it);
    }
    printf("\n");
    Solution s;
    printf("%d\n",s.maxArea(v));
    return 0;
}