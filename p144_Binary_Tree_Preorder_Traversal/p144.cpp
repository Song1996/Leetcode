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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> s;
        s.push(root);
        while(s.size()>0) {
            TreeNode* t = s.top();
            s.pop();
            ans.push_back(t->val);
            if(t->right!=NULL) s.push(t->right);
            if(t->left!=NULL)  s.push(t->left);
        }
        return ans;
    }
};

int main () {
    TreeNode* x = new TreeNode(1);
    x->right = new TreeNode(2);
    x->right->left = new TreeNode(3);
    Solution s;
    vector<int> y = s.preorderTraversal(x);
    for(int i = 0; i<y.size(); i++) {
        printf("%d ",y[i]);
    }printf("\n");
	return 0;
}