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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = bt(preorder, 0, preorder.size(), inorder, 0, inorder.size());
        return root;
    }

    TreeNode* bt(vector<int>& preorder, int pos, int poe, vector<int>& inorder, int ios, int ioe) {
        if(poe==pos) return NULL;
        TreeNode* root = new TreeNode(preorder[pos]);
        int i = ios;
        while(i<ioe && inorder[i]!=(root->val)) {
            i++;
        }
        if(i==ioe) assert(0);
        root->left = bt(preorder, pos+1, pos+1+(i-ios), inorder, ios, i);
        root->right = bt(preorder, pos+(i-ios)+1, poe, inorder, i+1, ioe);
        return root;
    }
    void display(TreeNode* root) {
        if(root==NULL) return;
        printf("%d ", root->val);
        display(root->left);
        display(root->right);
    }
};

int main () {
    vector<int> x1; 
    x1.push_back(3); x1.push_back(9); x1.push_back(20); 
    x1.push_back(15); x1.push_back(7);
    vector<int> x2;
    x2.push_back(9); x2.push_back(3); x2.push_back(15);
    x2.push_back(20); x2.push_back(7);
    Solution s;
    TreeNode* y = s.buildTree(x1, x2);
    s.display(y);
	return 0;
}