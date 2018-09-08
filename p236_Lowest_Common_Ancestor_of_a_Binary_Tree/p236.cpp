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
    bool dfs(TreeNode* root, TreeNode* goal, vector<TreeNode*>& mem) {
        if(root==goal){
            mem.push_back(root);
            return true;
        }
        mem.push_back(root);
        if(root->left && dfs(root->left, goal, mem)) return true;
        if(root->right && dfs(root->right, goal, mem)) return true;
        mem.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> mem1, mem2;
        dfs(root, p, mem1);
        dfs(root, q, mem2);
        int i = 0;
        while(mem1[i]==mem2[i]) {
            i++;
            if(i>=mem1.size() || i>=mem2.size()) break;
        }
        return mem1[i-1];
    }
};

int main() {
    return 0;
}