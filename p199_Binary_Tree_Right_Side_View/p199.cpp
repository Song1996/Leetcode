#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <assert.h>
#include <stdlib.h>
#include <fstream>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        dfs(ans, root, 0);
        return ans;
    }
    void dfs(vector<int>& ans, TreeNode* root, int d) {
        if(d>=ans.size()) ans.push_back(root->val);
        if(root->right!=NULL) dfs(ans, root->right, d+1);
        if(root->left!=NULL) dfs(ans, root->left, d+1);
    }
};

int main () {
	return 0;
}