#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cassert>
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
    int findSecondMinimumValue(TreeNode* root) {
        int m = INT_MAX, ans = INT_MAX;
        bool flag = false;
        if(root==NULL) return -1;
        helper1(root, m);
        helper(root, m, ans, flag);
        if(flag) return ans;
        else return -1;
    }
    void helper1(TreeNode* root, int& m) {
        if(root->left) helper1(root->left, m);
        if(root->val<m) m = root->val;
        if(root->right) helper1(root->right, m);
    }
    void helper(TreeNode* root, int m, int& ans, bool& flag) {
        if(root->left) helper(root->left, m, ans, flag);
        if(root->val > m) {
            if(!flag) {
                flag = true;
                ans = root->val;
            } else if(root->val < ans) ans = root->val;
        }
        if(root->right) helper(root->right, m, ans, flag);
    }
};

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    //root->right->left = new TreeNode(5);
    //root->right->right = new TreeNode(7);
    Solution s;
    printf("%d\n",s.findSecondMinimumValue(root));
    return 0;
}