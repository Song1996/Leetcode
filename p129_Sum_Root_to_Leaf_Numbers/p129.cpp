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
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        int ans = 0;
        int s = 0;
        dfs(root, s, ans);
        return ans;
    }
    void dfs(TreeNode* root, int& s, int& ans) {
        if(root->left==NULL && root->right==NULL) {
            ans += (s*10 + root->val);
            return;
        }
        s *= 10; s += root->val;
        if(root->left!=NULL) dfs(root->left, s, ans);
        if(root->right!=NULL) dfs(root->right, s, ans);
        s /= 10;
    }
};

int main () {
	return 0;
}