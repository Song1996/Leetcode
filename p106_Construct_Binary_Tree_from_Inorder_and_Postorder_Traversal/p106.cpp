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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = bt(postorder, 0, postorder.size(), inorder, 0, inorder.size());
        return root;
    }

    TreeNode* bt(vector<int>& postorder, int pos, int poe, vector<int>& inorder, int ios, int ioe) {
        if(poe==pos) return NULL;
        TreeNode* root = new TreeNode(postorder[poe-1]);
        int i = ios;
        while(i<ioe && inorder[i]!=(root->val)) {
            i++;
        }
        if(i==ioe) assert(0);
        root->left = bt(postorder, pos, pos+(i-ios), inorder, ios, i);
        root->right = bt(postorder, pos+(i-ios), poe-1, inorder, i+1, ioe);
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
    vector<int> postorder; 
    postorder.push_back(9); postorder.push_back(15); postorder.push_back(7); 
    postorder.push_back(20); postorder.push_back(3);
    vector<int> inorder;
    inorder.push_back(9); inorder.push_back(3); inorder.push_back(15);
    inorder.push_back(20); inorder.push_back(7);
    Solution s;
    TreeNode* y = s.buildTree(inorder, postorder);
    s.display(y);
	return 0;
}