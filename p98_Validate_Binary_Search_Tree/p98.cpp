#include <iostream>
#include <memory>
#include <vector>
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
    bool isValidBST(TreeNode* root) {
        return v(root, INT_MIN, INT_MAX, false, false);
    }
    bool v(TreeNode* root, int c, int f, bool int_min_meet, bool int_max_meet) {
        if(root==NULL) return true;
        if(c==INT_MIN &&root->val == INT_MIN && !int_min_meet) int_min_meet = true;
        else if(c==INT_MIN && root->val == INT_MIN && int_min_meet) return false;
        else if(f==INT_MAX && root->val == INT_MAX && !int_max_meet) int_max_meet = true;
        else if(f==INT_MAX && root->val == INT_MAX && int_max_meet) return false;
        else if(root->val<=c || root->val>=f) return false;
        if(root->left!=NULL && (root->left)->val>=root->val) return false;
        if(root->right!=NULL && (root->right)->val<=root->val) return false;
        return v(root->left,c,min(f,root->val),int_min_meet,int_max_meet)
                &&v(root->right,max(c,root->val),f,int_min_meet,int_max_meet);
    }
};

int main () {
	return 0;
}