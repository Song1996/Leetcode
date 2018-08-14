#include <memory>
#include <vector>
#include <map>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ans;
        for(int i = 0; i < n; i++){
            vector<int> t(n,-1);
            ans.push_back(t);
        }
        rehursive(ans, 1, 0, 0, n);
        return ans;
    }
    void rehursive(vector<vector<int> >& ans, int start, int x, int y, int height){
        if(height==0) return;
        if(height==1) {
            ans[x][y] = start;
            return;
        }
        for(int i = 0; i < height-1; i++) ans[x][y+i] = start++;
        for(int i = 0; i < height-1; i++) ans[x+i][y+height-1] = start++;
        for(int i = 0; i < height-1; i++) ans[x+height-1][y+height-1-i] = start++;
        for(int i = 0; i < height-1; i++) ans[x+height-1-i][y] = start++;
        rehursive(ans,start,x+1,y+1,height-2);
    }
};

int main () {
    int x = 4;
    Solution s;
    vector<vector<int> > y = s.generateMatrix(x);
    for(vector<vector<int> >::iterator it = y.begin(); it!=y.end(); it++){
        for(vector<int>::iterator itt = it->begin(); itt!=it->end(); itt++){
            printf("%2d ",*itt);
        }printf("\n");
    }
	return 0;
}