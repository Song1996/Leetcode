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
    int kthSmallest(TreeNode* root, int k) {
        //vector<int> mem;
        //preOrder(root, mem);
        int ans = helper(root, k);
        return ans;
    }
    int helper(TreeNode* root, int& k) {
        if(root==NULL) return -1;
        int ans = helper(root->left, k);
        if(ans>=0) return ans;
        if(k==1) return root->val;
        return helper(root->right, --k);
    }
};

int main() {

    return 0;
}