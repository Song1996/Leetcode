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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> s;
        s.push(root);
        while(s.size()>0) {
            TreeNode* t = s.top();
            if(t->right==NULL&&t->left==NULL) {
                s.pop();
                ans.push_back(t->val);
                continue;
            }
            if(t->right!=NULL) {
                s.push(t->right);
                t->right=NULL;
            }
            if(t->left!=NULL)  {
                s.push(t->left);
                t->left=NULL;
            }
        }
        return ans;
    }
};

int main () {
    TreeNode* x = new TreeNode(1);
    x->right = new TreeNode(2);
    x->right->left = new TreeNode(3);
    Solution s;
    vector<int> y = s.postorderTraversal(x);
    for(int i = 0; i<y.size(); i++) {
        printf("%d ",y[i]);
    }printf("\n");
	return 0;
}