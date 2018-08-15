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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root==NULL) return ans;
        dfs(ans, root, string(""));
        return ans;
    }
    void dfs(vector<string>& ans, TreeNode* root, string s) {
        if(root->left==NULL && root->right==NULL) {
            ans.push_back(s+to_string(root->val));
            return;
        }
        if(root->left!=NULL) dfs(ans, root->left, s+to_string(root->val)+"->");
        if(root->right!=NULL) dfs(ans, root->right, s+to_string(root->val)+"->");
        return;
    }
};

int main () {
	return 0;
}