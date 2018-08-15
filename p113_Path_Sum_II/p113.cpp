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
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > ans;
        if(root==NULL) return ans;
        vector<int> t;
        dfs(root, sum, ans, t);
        if(t.size()>0) assert(0);
        return ans;
    }
    void dfs(TreeNode* root, int sum, vector<vector<int> >& ans, vector<int>& m) {
        if(root->left==NULL && root->right==NULL) {
            if(sum == root->val){
                m.push_back(root->val);
                ans.push_back(m);
                m.pop_back();
            }
            return;
        }
        m.push_back(root->val);
        if(root->left!=NULL) dfs(root->left, sum-root->val, ans, m);
        if(root->right!=NULL) dfs(root->right, sum-root->val, ans, m);
        m.pop_back();
        return;
    }
};

int main () {
	return 0;
}