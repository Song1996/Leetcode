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
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        dfs(root);
        return;
    }
    TreeNode* dfs(TreeNode* root) {
        if(root->left==NULL) return (root->right==NULL)?root:dfs(root->right);
        if(root->right==NULL) {
            root->right = root->left;
            root->left = NULL;
            return dfs(root->right);
        }
        dfs(root->left)->right = root->right;
        TreeNode* tail = dfs(root->right);
        root->right = root->left;
        root->left = NULL;
        return tail;
    }
};

int main () {
	return 0;
}