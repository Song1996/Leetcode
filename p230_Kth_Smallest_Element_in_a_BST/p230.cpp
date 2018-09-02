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
        vector<int> mem;
        preOrder(root, mem);
        return mem[k];
    }
    void preOrder(TreeNode* root, vector<int>& mem) {
        if(root==NULL) return;
        preOrder(root->left, mem);
        mem.push_back(root->val);
        preOrder(root->right, mem);
        return;
    }
};

int main() {

    return 0;
}