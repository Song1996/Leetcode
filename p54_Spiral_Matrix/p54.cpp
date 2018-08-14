#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        /*int t[] = {1,2,3,6,9,8,7,4,5};
        vector<int> ans(t,t+sizeof(t)/sizeof(int));*/
        vector<int> ans;
        int height = matrix.size();
        if(height<=0) return ans;
        int width = matrix[0].size();
        for(vector<vector<int> >::iterator it=matrix.begin();it!=matrix.end();it++){
            if(width!=(it->size())) assert(0);
        }
        rehursive(matrix, ans, 0, 0, height, width);
        //printf("%lu\n",ans.size());
        return ans;
    }
    void rehursive(vector<vector<int> >& matrix, vector<int>& ans, int x, int y, int height, int width) {
        if(height==0||width==0) return;
        if(height==1) {
            ans.insert(ans.end(), matrix[x].begin()+y, matrix[x].begin()+y+width);
            return;
        }
        if(width==1) {
            for(int i = x; i < x+height; i++) ans.push_back(matrix[i][y]);
            return;
        }
        //printf("%d %d\n",x,y);
        //printf("%d %d\n\n",height,width);
        for(int i = y; i < y+width-1;  i++) ans.push_back(matrix[x][i]);
        for(int i = x; i < x+height-1; i++) ans.push_back(matrix[i][y+width-1]);
        for(int i = y+width-1; i > y;  i--) ans.push_back(matrix[x+height-1][i]);
        for(int i = x+height-1; i > x; i--) ans.push_back(matrix[i][y]);
        rehursive(matrix, ans, x+1, y+1, height-2, width-2);
    }
};

int main () {
    vector<vector<int> > x;
    vector<int> t;
    for(int i = 0; i < 4; i++) {
        t.clear();
        for(int j = 0; j < 4; j++) {
            t.push_back(i*3+j+1);
        }
        x.push_back(t);
    }
    for(vector<vector<int> >::iterator it = x.begin(); it!=x.end(); it++){
        for(vector<int>::iterator itt=it->begin(); itt!=it->end(); itt++){
            printf("%d ",*itt);
        }printf("\n");
    }
    Solution s;
    vector<int> y =s.spiralOrder(x);
    for(vector<int>::iterator it = y.begin();it!=y.end();it++) printf("%d ",*it);
    printf("\n");
	return 0;
}
