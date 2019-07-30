#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people,0);
        //cout<<sqrt(candies)<<' '<<ans.size()<<endl;
        int m = int(sqrt(2*candies)-1);
        if( ((m+1)*(m+2))/2 <= candies) m++;
        int left = candies - ((m*(m+1))/2);
        int baseTurnNum = m/num_people;
        for(int i = 0; i < num_people; i++) {
            ans[i] = ((i+1 + i+1+num_people*(baseTurnNum-1)) * baseTurnNum) / 2;
            if( i < m%num_people) {
                ans[i] += i+1+num_people*baseTurnNum;
            } else if (i == m%num_people) {
                ans[i] += left;
            }
        }
        return ans;
    }
};