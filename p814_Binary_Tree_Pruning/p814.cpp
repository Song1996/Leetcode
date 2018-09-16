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
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root->left!=NULL) root->left = pruneTree(root->left);
        if(root->right!=NULL) root->right = pruneTree(root->right);
        if(root->left==NULL&&root->right==NULL&&root->val==0) return NULL;
        return root;
    }
};

int main() {
    return 0;
}