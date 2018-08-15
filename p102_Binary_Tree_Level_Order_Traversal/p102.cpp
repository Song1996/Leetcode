#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if(root==NULL) return ans;
        dfs(ans, root, 0);
        return ans;
    }
    void dfs(vector<vector<int> >& ans, TreeNode* root, int depth) {
        if(depth==ans.size()) {
            vector<int> t;
            t.push_back(root->val);
            ans.push_back(t);
        }else {
            ans[depth].push_back(root->val);
        }
        if(root->left!=NULL) dfs(ans, root->left, depth+1);
        if(root->right!=NULL) dfs(ans, root->right, depth+1);
    }
};

int main () {
    TreeNode* x = new TreeNode(3);
    x->left = new TreeNode(9);
    x->right = new TreeNode(20);
    x->right->left = new TreeNode(15);
    x->right->right = new TreeNode(7);
    Solution s;
    vector<vector<int> > y = s.levelOrder(x);
    for(int i = 0; i<y.size(); i++) {
        for(int j = 0; j<y[i].size(); j++) {
            printf("%d ",y[i][j]);
        }printf("\n");
    }
	return 0;
}